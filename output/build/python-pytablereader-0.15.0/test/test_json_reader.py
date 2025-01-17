# encoding: utf-8

"""
.. codeauthor:: Tsuyoshi Hombashi <tsuyoshi.hombashi@gmail.com>
"""

from __future__ import print_function
from __future__ import unicode_literals

import collections
from decimal import Decimal

from path import Path
from pytablereader import InvalidTableNameError
from tabledata import TableData
from pytablereader.interface import TableLoader
import pytest

import pytablereader as ptr
import pytablewriter as ptw


Data = collections.namedtuple("Data", "value expected")

test_data_empty = Data(
    """[]""",
    [
        TableData("tmp", [], []),
    ])

test_data_single_01 = Data(
    """[
        {"attr_b": 4, "attr_c": "a", "attr_a": 1},
        {"attr_b": 2.1, "attr_c": "bb", "attr_a": 2},
        {"attr_b": 120.9, "attr_c": "ccc", "attr_a": 3}
    ]""",
    [
        TableData(
            "json1",
            ["attr_a", "attr_b", "attr_c"],
            [
                {'attr_a': 1, 'attr_b': 4, 'attr_c': 'a'},
                {'attr_a': 2, 'attr_b': 2.1, 'attr_c': 'bb'},
                {'attr_a': 3, 'attr_b': 120.9, 'attr_c': 'ccc'},
            ]),
    ])

test_data_single_02 = Data(
    """[
        {"attr_a": 1},
        {"attr_b": 2.1, "attr_c": "bb"}
    ]""",
    [
        TableData(
            "json1",
            ["attr_a", "attr_b", "attr_c"],
            [
                {'attr_a': 1},
                {'attr_b': 2.1, 'attr_c': 'bb'},
            ]),
    ])

test_data_single_03 = Data(
    """[
    {"attr_b": "4", "attr_c": "a", "attr_a": "1"},
    {"attr_b": "2.1", "attr_c": "bb", "attr_a": "2"},
    {"attr_b": "120.9", "attr_c": "ccc", "attr_a": "3"}
]""",
    [
        TableData(
            "json1",
            ["attr_a", "attr_b", "attr_c"],
            [
                {'attr_a': 1, 'attr_b': 4, 'attr_c': 'a'},
                {'attr_a': 2, 'attr_b': '2.1', 'attr_c': 'bb'},
                {'attr_a': 3, 'attr_b': '120.9', 'attr_c': 'ccc'},
            ]),
    ])

test_data_multi_01 = Data(
    """{
        "table_a" : [
            {"attr_b": 4, "attr_c": "a", "attr_a": 1},
            {"attr_b": 2.1, "attr_c": "bb", "attr_a": 2},
            {"attr_b": 120.9, "attr_c": "ccc", "attr_a": 3}
        ],
        "table_b" : [
            {"a": 1, "b": 4},
            {"a": 2 },
            {"a": 3, "b": 120.9}
        ]
    }""",
    [
        TableData(
            "table_a",
            ["attr_a", "attr_b", "attr_c"],
            [
                {'attr_a': 1, 'attr_b': 4, 'attr_c': 'a'},
                {'attr_a': 2, 'attr_b': 2.1, 'attr_c': 'bb'},
                {'attr_a': 3, 'attr_b': 120.9, 'attr_c': 'ccc'},
            ]),
        TableData(
            "table_b",
            ["a", "b"],
            [
                {'a': 1, 'b': 4},
                {'a': 2, },
                {'a': 3, 'b': 120.9},
            ]),
    ])

test_data_multi_02 = Data(
    """{
        "table_a" : [
            {"attr_b": 4, "attr_c": "a", "attr_a": 1},
            {"attr_b": 2.1, "attr_c": "bb", "attr_a": 2},
            {"attr_b": 120.9, "attr_c": "ccc", "attr_a": 3}
        ],
        "table_b" : [
            {"a": 1, "b": 4},
            {"a": 2 },
            {"a": 3, "b": 120.9}
        ]
    }""",
    [
        TableData(
            "table_a",
            ["attr_a", "attr_b", "attr_c"],
            [
                {'attr_a': 1, 'attr_b': 4, 'attr_c': 'a'},
                {'attr_a': 2, 'attr_b': 2.1, 'attr_c': 'bb'},
                {'attr_a': 3, 'attr_b': 120.9, 'attr_c': 'ccc'},
            ]),
        TableData(
            "table_b",
            ["a", "b"],
            [
                {'a': 1, 'b': 4},
                {'a': 2, },
                {'a': 3, 'b': 120.9},
            ]),
    ])

test_data_single_10 = Data(
    """{
        "attr_a": [1, 2, 3],
        "attr_b": [4, 2.1, 120.9],
        "attr_c": ["a", "bb", "ccc"]
}""",
    [
        TableData(
            "json1",
            ["attr_a", "attr_b", "attr_c"],
            [
                [1, 4, 'a'],
                [2, Decimal('2.1'), 'bb'],
                [3, Decimal('120.9'), 'ccc']
            ]),
    ])

test_data_multi_10 = Data(
    """{
        "table_a" : {
            "attr_a": [1, 2, 3],
            "attr_b": [4, 2.1, 120.9],
            "attr_c": ["a", "bb", "ccc"]
        },
        "table_b" : {
            "a": [1, 3],
            "b": [4, 120.9]
        }
    }""",
    [
        TableData(
            "table_a",
            ["attr_a", "attr_b", "attr_c"],
            [
                [1, 4, 'a'],
                [2, Decimal('2.1'), 'bb'],
                [3, Decimal('120.9'), 'ccc']
            ]),
        TableData(
            "table_b",
            ["a", "b"],
            [
                [1, 4],
                [3, Decimal('120.9')],
            ]),
    ])


class Test_JsonTableFileLoader_make_table_name(object):

    def setup_method(self, method):
        TableLoader.clear_table_count()

    @pytest.mark.parametrize(["value", "source", "expected"], [
        ["%(filename)s", "/path/to/data.json", "data"],
        ["prefix_%(filename)s", "/path/to/data.json", "prefix_data"],
        ["%(filename)s_suffix", "/path/to/data.json", "data_suffix"],
        [
            "prefix_%(filename)s_suffix",
            "/path/to/data.json",
            "prefix_data_suffix"
        ],
        [
            "%(filename)s%(filename)s",
            "/path/to/data.json",
            "datadata"
        ],
        [
            "%(format_name)s%(format_id)s_%(filename)s",
            "/path/to/data.json",
            "json0_data"
        ],
        ["hoge_%(filename)s", None, "hoge"],
        ["hoge_%(filename)s", "", "hoge"],
        [
            "%(%(filename)s)",
            "/path/to/data.json",
            "%(data)"
        ],
    ])
    def test_normal(self, value, source, expected):
        loader = ptr.JsonTableFileLoader(source)
        loader.table_name = value

        assert loader.make_table_name() == expected

    @pytest.mark.parametrize(["value", "source", "expected"], [
        [None, "/path/to/data.json", ValueError],
        ["", "/path/to/data.json", ValueError],
        ["%(filename)s", None, InvalidTableNameError],
        ["%(filename)s", "", InvalidTableNameError],
    ])
    def test_exception(self, value, source, expected):
        loader = ptr.JsonTableFileLoader(source)
        loader.table_name = value

        with pytest.raises(expected):
            loader.make_table_name()


class Test_JsonTableFileLoader_load(object):

    def setup_method(self, method):
        TableLoader.clear_table_count()

    @pytest.mark.parametrize(
        [
            "table_text", "filename", "table_name",
            "expected_tabletuple_list",
        ],
        [
            [
                test_data_single_01.value, "json1.json", "%(key)s",
                test_data_single_01.expected
            ],
            [
                test_data_single_02.value, "json1.json", "%(key)s",
                test_data_single_02.expected
            ],
            [
                test_data_multi_01.value, "tmp.json", "%(key)s",
                test_data_multi_01.expected
            ],
            [
                test_data_multi_02.value, "tmp.json", "%(key)s",
                test_data_multi_02.expected
            ],
            [
                test_data_single_10.value, "json1.json", "%(key)s",
                test_data_single_10.expected
            ],
            [
                test_data_multi_10.value, "tmp.json", "%(key)s",
                test_data_multi_10.expected
            ],
        ])
    def test_normal(
            self, tmpdir, table_text, filename,
            table_name, expected_tabletuple_list):
        file_path = Path(str(tmpdir.join(filename)))
        file_path.parent.makedirs_p()

        with open(file_path, "w") as f:
            f.write(table_text)

        loader = ptr.JsonTableFileLoader(file_path)
        #loader.table_name = table_name

        load = False
        for tabledata in loader.load():
            print("[actual]\n{}".format(ptw.dump_tabledata(tabledata)))

            assert tabledata in expected_tabletuple_list
            load = True

        assert load

    @pytest.mark.parametrize(
        ["table_text", "filename", "expected"],
        [
            [
                "[]",
                "tmp.json",
                ptr.InvalidDataError,
            ],
            [
                """[
                    {"attr_b": 4, "attr_c": "a", "attr_a": {"aaa": 1}}
                ]""",
                "tmp.json",
                ptr.ValidationError,
            ],
        ])
    def test_exception(
            self, tmpdir, table_text, filename, expected):
        p_file_path = tmpdir.join(filename)

        with open(str(p_file_path), "w") as f:
            f.write(table_text)

        loader = ptr.JsonTableFileLoader(str(p_file_path))

        with pytest.raises(expected):
            for _tabletuple in loader.load():
                pass

    @pytest.mark.parametrize(["filename", "expected"], [
        ["", ptr.InvalidFilePathError],
        [None, ptr.InvalidFilePathError],
    ])
    def test_null(
            self, tmpdir, filename, expected):
        loader = ptr.JsonTableFileLoader(filename)

        with pytest.raises(expected):
            for _tabletuple in loader.load():
                pass


class Test_JsonTableTextLoader_make_table_name(object):

    def setup_method(self, method):
        TableLoader.clear_table_count()

    @pytest.mark.parametrize(["value", "expected"], [
        ["%(format_name)s%(format_id)s", "json0"],
        ["tablename", "tablename"],
        ["[table]", "[table]"],
    ])
    def test_normal(self, value, expected):
        loader = ptr.JsonTableTextLoader("dummy")
        loader.table_name = value

        assert loader.make_table_name() == expected

    @pytest.mark.parametrize(["value", "source", "expected"], [
        [None, "tablename", ValueError],
        ["", "tablename", ValueError],
    ])
    def test_exception(self, value, source, expected):
        loader = ptr.JsonTableTextLoader(source)
        loader.table_name = value

        with pytest.raises(expected):
            loader.make_table_name()


class Test_JsonTableTextLoader_load(object):

    def setup_method(self, method):
        TableLoader.clear_table_count()

    @pytest.mark.parametrize(
        [
            "table_text", "table_name",
            "expected_tabletuple_list",
        ],
        [
            [
                test_data_single_01.value, "json1",
                test_data_single_01.expected,
            ],
            [
                test_data_single_02.value, "json1",
                test_data_single_02.expected,
            ],
            [
                test_data_multi_01.value, "%(default)s",
                test_data_multi_01.expected
            ],
            [
                test_data_single_03.value, "%(key)s",
                test_data_single_03.expected
            ],
            [
                test_data_single_10.value, "%(key)s",
                test_data_single_10.expected
            ],
            [
                test_data_multi_10.value, "%(key)s",
                test_data_multi_10.expected
            ],
        ])
    def test_normal(self, table_text, table_name, expected_tabletuple_list):
        ptr.JsonTableFileLoader.clear_table_count()
        loader = ptr.JsonTableTextLoader(table_text)
        loader.table_name = table_name

        load = False
        for tabledata in loader.load():
            print("[actual]\n{}".format(ptw.dump_tabledata(tabledata)))

            assert tabledata in expected_tabletuple_list
            load = True

        assert load

    @pytest.mark.parametrize(["table_text", "expected"], [
        [
            "[]",
            ptr.InvalidDataError,
        ],
        [
            """[
                {"attr_b": 4, "attr_c": "a", "attr_a": {"aaa": 1}}
            ]""",
            ptr.ValidationError,
        ],
    ])
    def test_exception(self, table_text, expected):
        loader = ptr.JsonTableTextLoader(table_text)
        loader.table_name = "dummy"

        with pytest.raises(expected):
            for _tabletuple in loader.load():
                pass

    @pytest.mark.parametrize(["table_text", "expected"], [
        ["", ptr.InvalidDataError],
        [None, ptr.InvalidDataError],
    ])
    def test_null(self, table_text, expected):
        loader = ptr.JsonTableTextLoader(table_text)
        loader.table_name = "dummy"

        with pytest.raises(expected):
            for _tabletuple in loader.load():
                pass
