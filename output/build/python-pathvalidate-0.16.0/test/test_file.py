# encoding: utf-8

"""
.. codeauthor:: Tsuyoshi Hombashi <tsuyoshi.hombashi@gmail.com>
"""

from __future__ import absolute_import
from __future__ import unicode_literals

import itertools
import platform
import random

from pathvalidate import *
from pathvalidate._file import FileSanitizer
import pytest

from ._common import (
    make_random_str,
    INVALID_PATH_CHARS,
    INVALID_FILENAME_CHARS,
    INVALID_WIN_PATH_CHARS,
    INVALID_WIN_FILENAME_CHARS,
    VALID_FILENAME_CHARS,
    VALID_PATH_CHARS
)


nan = float("nan")
inf = float("inf")

random.seed(0)

VALID_PLATFORM_NAME_LIST = ["linux", "windows"]

WIN_RESERVED_FILE_NAME_LIST = [
    "CON", "con",
    "PRN", "prn",
    "AUX", "aux",
    "NUL", "nul",
] + [
    "{:s}{:d}".format(name, num)
    for name, num
    in itertools.product(["COM", "com", "LPT", "lpt"], range(1, 10))
]

VALID_MULTIBYTE_NAME_LIST = [
    "新しいテキスト ドキュメント.txt",
    "新規 Microsoft Excel Worksheet.xlsx",
]


class Test_validate_filename:
    VALID_CHAR_LIST = VALID_FILENAME_CHARS
    INVALID_CHAR_LIST = INVALID_WIN_FILENAME_CHARS

    @pytest.mark.parametrize(
        ["value", "platform_name"],
        itertools.chain.from_iterable([
            [
                arg_list for arg_list in itertools.product(
                    [make_random_str(64) + valid_char + make_random_str(64)],
                    VALID_PLATFORM_NAME_LIST
                )
            ]
            for valid_char in VALID_CHAR_LIST
        ])
    )
    def test_normal(self, value, platform_name):
        validate_filename(value, platform_name)

    @pytest.mark.parametrize(
        ["value", "platform_name"],
        itertools.chain.from_iterable([
            [
                arg_list for arg_list in itertools.product(
                    [multibyte_name], VALID_PLATFORM_NAME_LIST)
            ]
            for multibyte_name in VALID_MULTIBYTE_NAME_LIST
        ])
    )
    def test_normal_multibyte(self, value, platform_name):
        validate_filename(value, platform_name)

    @pytest.mark.parametrize(
        ["value", "max_filename_len", "expected"],
        [
            ["valid_length", 255, None],
            ["invalid_length", 2, InvalidLengthError],
            ["invalid_length" * 100, 255, InvalidLengthError],
        ]
    )
    def test_normal_max_filename_len(
            self, value, max_filename_len, expected):
        if expected is None:
            validate_filename(value, max_filename_len=max_filename_len)
        else:
            with pytest.raises(expected):
                validate_filename(value, max_filename_len=max_filename_len)

    @pytest.mark.parametrize(
        ["value", "platform_name"],
        itertools.chain.from_iterable([
            [
                arg_list for arg_list in itertools.product(
                    [make_random_str(64) + invalid_char + make_random_str(64)],
                    VALID_PLATFORM_NAME_LIST
                )
            ]
            for invalid_char in INVALID_FILENAME_CHARS
        ])
    )
    def test_exception_invalid_char(self, value, platform_name):
        with pytest.raises(InvalidCharError):
            validate_filename(value, platform_name)

    @pytest.mark.parametrize(["value"], [
        [make_random_str(64) + invalid_char + make_random_str(64)]
        for invalid_char in set(INVALID_WIN_PATH_CHARS).difference(
            set(INVALID_PATH_CHARS + INVALID_FILENAME_CHARS))
    ])
    def test_exception_win_invalid_char(self, value):
        with pytest.raises(InvalidCharWindowsError):
            validate_filename(value, platform_name="windows")

    @pytest.mark.parametrize(["value", "expected"], [
        [reserved_keyword, InvalidReservedNameError]
        for reserved_keyword in WIN_RESERVED_FILE_NAME_LIST
    ])
    def test_exception_win_reserved_name(self, value, expected):
        with pytest.raises(expected):
            validate_filename(value, platform_name="windows")

    @pytest.mark.parametrize(["value", "expected"], [
        [None, ValueError],
        ["", NullNameError],
        ["a" * 256, InvalidLengthError],
        [1, TypeError],
        [True, TypeError],
        [nan, TypeError],
        [inf, TypeError],
    ])
    def test_exception(self, value, expected):
        with pytest.raises(expected):
            validate_filename(value)


class Test_validate_file_path:
    VALID_CHAR_LIST = VALID_PATH_CHARS
    VALID_MULTIBYTE_PATH_LIST = [
        "\\\\localhost\\Users\\新しいフォルダー\\あいうえお.txt",
        "\\\\localhost\\新しいフォルダー\\ユーザ属性.txt",
    ]
    WIN_VALID_PATH_LIST = [
        '\\\\localhost\\Users\\test\\AppData\\Local\\Temp\\pytest-of-test\\pytest-0\\test_exception__hoge_csv_heade1\\hoge.csv',
        '\\\\localhost/Users/test/AppData/Local/Temp/pytest-of-test/pytest-0/test_exception__hoge_csv_heade1/hoge.csv',
        '\\\\localhost\\Users\\test\\AppData/Local\\Temp/pytest-of-test\\pytest-0/test_exception__hoge_csv_heade1\\hoge.csv',
        '\\\\localhost\\Users',
        '\\\\localhost\\',
        '\\Users',
    ]

    @pytest.mark.parametrize(
        ["value", "platform_name"],
        itertools.chain.from_iterable([
            [
                arg_list for arg_list in itertools.product(
                    [make_random_str(64) + valid_char + make_random_str(64)],
                    VALID_PLATFORM_NAME_LIST
                )
            ]
            for valid_char in VALID_CHAR_LIST
        ])
    )
    def test_normal(self, value, platform_name):
        validate_file_path(value, platform_name)

    @pytest.mark.parametrize(
        ["value", "platform_name"],
        itertools.chain.from_iterable([
            [
                arg_list for arg_list in itertools.product(
                    [valid_path], VALID_PLATFORM_NAME_LIST)
            ]
            for valid_path in VALID_MULTIBYTE_PATH_LIST
        ])
    )
    def test_normal_multibyte(self, value, platform_name):
        validate_file_path(value, platform_name)

    @pytest.mark.parametrize(["value"], [
        [valid_path]
        for valid_path in WIN_VALID_PATH_LIST
    ])
    def test_normal_win(self, value):
        validate_file_path(value, "windows")

    @pytest.mark.parametrize(
        ["value", "platform_name", "max_path_len", "expected"],
        [
            ["a" * 4096, "linux", None, None],
            ["a" * 4097, "linux", None, InvalidLengthError],
            ["a" * 255, "linux", 100, InvalidLengthError],
            ["a" * 260, "windows", None, None],
            ["a" * 261, "windows", None, InvalidLengthError],
        ]
    )
    def test_normal_max_path_len(
            self, value, platform_name, max_path_len, expected):
        if expected is None:
            validate_file_path(
                value, platform_name=platform_name, max_path_len=max_path_len)
        else:
            with pytest.raises(expected):
                validate_file_path(
                    value, platform_name=platform_name, max_path_len=max_path_len)

    @pytest.mark.parametrize(["value"], [
        [make_random_str(64) + invalid_char + make_random_str(64)]
        for invalid_char in INVALID_PATH_CHARS
    ])
    def test_exception_invalid_char(self, value):
        with pytest.raises(InvalidCharError):
            validate_file_path(value)

    @pytest.mark.parametrize(["value"], [
        [make_random_str(64) + invalid_char + make_random_str(64)]
        for invalid_char in set(INVALID_WIN_PATH_CHARS).difference(
            set(INVALID_PATH_CHARS))
    ])
    def test_exception_invalid_win_char(self, value):
        with pytest.raises(InvalidCharWindowsError):
            validate_file_path(value, platform_name="windows")

    @pytest.mark.parametrize(["value", "expected"], [
        [None, ValueError],
        ["", NullNameError],
        [1, TypeError],
        [True, TypeError],
    ])
    def test_exception(self, value, expected):
        with pytest.raises(expected):
            validate_file_path(value)


@pytest.mark.skipif("platform.system() != 'Windows'")
class Test_validate_win_file_path:
    VALID_CHAR_LIST = VALID_PATH_CHARS

    @pytest.mark.parametrize(["value"], [
        ['C:\\Users\\test\\AppData\\Local\\Temp\\pytest-of-test\\pytest-0\\test_exception__hoge_csv_heade1\\hoge.csv'],
        ['Z:\\Users\\test\\AppData\\Local\\Temp\\pytest-of-test\\pytest-0\\test_exception__hoge_csv_heade1\\hoge.csv'],
        ['C:/Users/test/AppData/Local/Temp/pytest-of-test/pytest-0/test_exception__hoge_csv_heade1/hoge.csv'],
        ['C:\\Users/test\\AppData/Local\\Temp/pytest-of-test\\pytest-0/test_exception__hoge_csv_heade1\\hoge.csv'],
        ['C:\\Users'],
        ['C:\\'],
        ['\\Users'],
    ])
    def test_normal(self, value):
        validate_file_path(value)


class Test_sanitize_filename:
    SANITIZE_CHAR_LIST = INVALID_WIN_FILENAME_CHARS
    NOT_SANITIZE_CHAR_LIST = VALID_FILENAME_CHARS
    REPLACE_TEXT_LIST = ["", "_"]

    @pytest.mark.parametrize(["value", "replace_text", "expected"], [
        ["A" + c + "B", rep, "A" + rep + "B"]
        for c, rep in itertools.product(
            SANITIZE_CHAR_LIST, REPLACE_TEXT_LIST)
    ] + [
        ["A" + c + "B", rep, "A" + c + "B"]
        for c, rep in itertools.product(
            NOT_SANITIZE_CHAR_LIST, REPLACE_TEXT_LIST)
    ])
    def test_normal(self, value, replace_text, expected):
        sanitized_name = sanitize_filename(value, replace_text)
        assert sanitized_name == expected
        validate_filename(sanitized_name)

    @pytest.mark.parametrize(["value", "replace_text", "expected"], [
        ["あい/うえお.txt", "", "あいうえお.txt"],
        ["属/性.txt", "-", "属-性.txt"],
    ])
    def test_normal_multibyte(self, value, replace_text, expected):
        sanitized_name = sanitize_filename(value, replace_text)
        assert sanitized_name == expected
        validate_filename(sanitized_name)

    @pytest.mark.parametrize(
        ["value", "max_filename_len", "expected"],
        [
            ["a" * 10, 255, 10],
            ["invalid_length" * 100, 255, 255],
            ["invalid_length" * 100, 10, 10],
        ]
    )
    def test_normal_max_filename_len(
            self, value, max_filename_len, expected):
        assert len(sanitize_filename(
            value, max_filename_len=max_filename_len)) == expected

    @property
    def platform_win(self):
        return "windows"

    @property
    def platform_linux(self):
        return "linux"

    @pytest.mark.parametrize(["value", "test_platform", "expected"], [
        [reserved.lower(), "windows", reserved.lower() + "_"]
        for reserved in WIN_RESERVED_FILE_NAME_LIST
    ] + [
        [reserved.upper(), "windows", reserved.upper() + "_"]
        for reserved in WIN_RESERVED_FILE_NAME_LIST
    ] + [
        [reserved, "linux", reserved]
        for reserved in WIN_RESERVED_FILE_NAME_LIST
    ])
    def test_normal_win_reserved_name(
            self, monkeypatch, value, test_platform, expected):
        if test_platform == "windows":
            patch = self.platform_win
        elif test_platform == "linux":
            patch = self.platform_linux
        else:
            raise ValueError(
                "unexpected test platform: {}".format(test_platform))

        monkeypatch.setattr(
            FileSanitizer, "platform_name", patch)

        assert sanitize_filename(value) == expected

    @pytest.mark.parametrize(["value", "expected"], [
        [None, ValueError],
        [1, TypeError],
        [True, TypeError],
    ])
    def test_exception_type(self, value, expected):
        with pytest.raises(expected):
            sanitize_filename(value)


class Test_sanitize_file_path:
    SANITIZE_CHAR_LIST = INVALID_WIN_PATH_CHARS
    NOT_SANITIZE_CHAR_LIST = VALID_PATH_CHARS
    REPLACE_TEXT_LIST = ["", "_"]

    @pytest.mark.parametrize(
        ["value", "replace_text", "expected"],
        [
            ["A" + c + "B", rep, "A" + rep + "B"]
            for c, rep in itertools.product(
                SANITIZE_CHAR_LIST, REPLACE_TEXT_LIST)
        ] + [
            ["A" + c + "B", rep, "A" + c + "B"]
            for c, rep in itertools.product(
                NOT_SANITIZE_CHAR_LIST, REPLACE_TEXT_LIST)
        ]
    )
    def test_normal(self, value, replace_text, expected):
        sanitized_name = sanitize_file_path(value, replace_text)
        assert sanitized_name == expected
        validate_file_path(sanitized_name)

    @pytest.mark.parametrize(["value", "replace_text", "expected"], [
        ["/tmp/あいう\0えお.txt", "", "/tmp/あいうえお.txt"],
        ["/tmp/属\0性.txt", "-", "/tmp/属-性.txt"],
    ])
    def test_normal_multibyte(self, value, replace_text, expected):
        sanitized_name = sanitize_file_path(value, replace_text)
        assert sanitized_name == expected
        validate_file_path(sanitized_name)

    @pytest.mark.parametrize(["value", "expected"], [
        [None, ValueError],
        [1, TypeError],
        [True, TypeError],
        [nan, TypeError],
        [inf, TypeError],
    ])
    def test_exception_type(self, value, expected):
        with pytest.raises(expected):
            sanitize_file_path(value)
