# encoding: utf-8

"""
.. codeauthor:: Tsuyoshi Hombashi <tsuyoshi.hombashi@gmail.com>
"""

from __future__ import print_function
from __future__ import unicode_literals

import collections
from decimal import Decimal

from path import Path
from pytablereader.interface import TableLoader
import pytest
from simplesqlite import SimpleSQLite
from tabledata import TableData

import pytablereader as ptr
import pytablewriter as ptw


Data = collections.namedtuple("Data", "value expected")

test_data_00 = Data(
    TableData("tmp",
              ["attr_a", "attr_b", "attr_c"],
              [
                  [1, 4, "a"],
                  [2, Decimal("2.1"), "bb"],
                  [3, Decimal("120.9"), "ccc"],
              ]),
    [
        TableData("tmp",
                  ["attr_a", "attr_b", "attr_c"],
                  [
                      [1, 4, "a"],
                      [2, Decimal("2.1"), "bb"],
                      [3, Decimal("120.9"), "ccc"],
                  ]),
    ])

test_data_01 = Data(
    TableData("foo_bar",
              ["attr_a", "attr_b", "attr_c"],
              [
                  ["aaaa", "bbbb", "cccc"],
                  [1, 4, "a"],
                  [2, "2.1", "bb"],
                  [3, "120.9", "ccc"],
              ]),
    [
        TableData("foo_bar",
                  ["attr_a", "attr_b", "attr_c"],
                  [
                      ["aaaa", "bbbb", "cccc"],
                      ["1", "4", "a"],
                      ["2", "2.1", "bb"],
                      ["3", "120.9", "ccc"],
                  ]),
    ])

test_data_02 = Data(
    TableData("foo_bar",
              ["attr_a", "attr_b", "attr_c"],
              [
                  [3, "120.9", "ccc"],
              ]),
    [
        TableData("foo_bar",
                  ["attr_a", "attr_b", "attr_c"],
                  [
                      [3, "120.9", "ccc"],
                  ]),
    ])

test_data_03 = Data(
    TableData("tmp",
              ["attr_a", "attr_b", "attr_c"],
              [
                  [1, 4, "a"],
                  [2, "2.1", "bb"],
                  [3, "120.9", "ccc"],
              ]),
    [
        TableData("tmp",
                  ["attr_a", "attr_b", "attr_c"],
                  [
                      [1, 4, "a"],
                      [2, "2.1", "bb"],
                      [3, "120.9", "ccc"],
                  ]),
    ])

test_data_04 = Data(
    TableData("tmp",
              ["attr_a", "attr_b", "attr_c"],
              [
                  [1, 4, "a"],
                  [2, "2.1", "bb"],
                  [3, "120.9", "ccc"],
              ]),
    [
        TableData("tmp",
                  ["attr_a", "attr_b", "attr_c"],
                  [
                      [1, 4, "a"],
                      [2, "2.1", "bb"],
                      [3, "120.9", "ccc"],
                  ]),
    ])

test_data_05 = Data(
    TableData("tmp",
              ["姓", "名", "生年月日", "郵便番号", "住所", "電話番号"],
              [
                  ["山田", "太郎", "2001/1/1", "100-0002",
                   "東京都千代田区皇居外苑", "03-1234-5678"],
                  ["山田", "次郎", "2001/1/2", "251-0036",
                   "神奈川県藤沢市江の島１丁目", "03-9999-9999"],
              ]),
    [
        TableData("tmp",
                  ["姓", "名", "生年月日", "郵便番号", "住所", "電話番号"],
                  [
                      ["山田", "太郎", "2001/1/1", "100-0002",
                       "東京都千代田区皇居外苑", "03-1234-5678"],
                      ["山田", "次郎", "2001/1/2", "251-0036",
                       "神奈川県藤沢市江の島１丁目", "03-9999-9999"],
                  ]),
    ])


class Test_SqliteFileLoader_load(object):

    def setup_method(self, method):
        TableLoader.clear_table_count()

    @pytest.mark.parametrize(
        [
            "test_id",
            "tabledata",
            "filename",
            "header_list",
            "expected",
        ],
        [
            [
                0, test_data_00.value,
                "tmp.sqlite",
                [],
                test_data_00.expected,
            ],
            [
                1, test_data_01.value,
                "foo_bar.sqlite",
                ["attr_a", "attr_b", "attr_c"],
                test_data_01.expected,
            ],
            [
                2, test_data_02.value,
                "foo_bar.sqlite",
                ["attr_a", "attr_b", "attr_c"],
                test_data_02.expected,
            ],
            [
                3, test_data_03.value,
                "tmp.sqlite",
                [],
                test_data_03.expected,
            ],
            [
                4, test_data_04.value,
                "tmp.sqlite",
                [],
                test_data_04.expected,
            ],
            [
                5, test_data_05.value,
                "tmp.sqlite",
                [],
                test_data_05.expected,
            ],
        ])
    def test_normal(
            self, tmpdir,
            test_id, tabledata, filename, header_list, expected):
        file_path = Path(str(tmpdir.join(filename)))
        file_path.parent.makedirs_p()

        con = SimpleSQLite(file_path, "w")

        con.create_table_from_tabledata(tabledata)

        loader = ptr.SqliteFileLoader(file_path)
        loader.header_list = header_list

        for tabledata in loader.load():
            print("test-id={}".format(test_id))
            print(ptw.dump_tabledata(tabledata))

            assert tabledata in expected

    @pytest.mark.parametrize(
        [
            "filename",
            "header_list",
            "expected",
        ],
        [
            ["", [], ptr.InvalidFilePathError],
            [None, [], ptr.InvalidFilePathError],
        ])
    def test_null(
            self, tmpdir, filename, header_list, expected):

        loader = ptr.SqliteFileLoader(filename)
        loader.header_list = header_list

        with pytest.raises(expected):
            for _tabletuple in loader.load():
                pass
