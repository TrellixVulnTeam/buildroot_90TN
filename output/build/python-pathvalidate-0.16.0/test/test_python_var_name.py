# encoding: utf-8

"""
.. codeauthor:: Tsuyoshi Hombashi <tsuyoshi.hombashi@gmail.com>
"""

from __future__ import absolute_import
from __future__ import unicode_literals

import itertools
import string

from pathvalidate import *
import pytest

from ._common import INVALID_PYTHON_VAR_CHARS


RESERVED_KEYWORDS = [
    "and", "del", "from", "not", "while",
    "as", "elif", "global", "or", "with",
    "assert", "else", "if", "pass", "yield",
    "break", "except", "import", "print",
    "class", "exec", "in", "raise",
    "continue", "finally", "is", "return",
    "def", "for", "lambda", "try",
    "False", "True", "None", "NotImplemented", "Ellipsis",
]


class Test_validate_python_var_name:
    VALID_CHAR_LIST = [
        c for c in string.digits + string.ascii_letters + "_"
    ]
    INVALID_CHAR_LIST = INVALID_PYTHON_VAR_CHARS

    @pytest.mark.parametrize(["value"], [
        ["abc" + valid_char + "hoge123"]
        for valid_char in VALID_CHAR_LIST
    ])
    def test_normal(self, value):
        validate_python_var_name(value)

    @pytest.mark.parametrize(["value"], [
        ["abc" + invalid_char + "hoge123"]
        for invalid_char in INVALID_CHAR_LIST
    ])
    def test_exception_invalid_char(self, value):
        with pytest.raises(InvalidCharError):
            validate_python_var_name(value)

    @pytest.mark.parametrize(["value"], [
        [invalid_char + "hoge123"]
        for invalid_char in string.digits + "_"
    ])
    def test_exception_invalid_first_char(self, value):
        with pytest.raises(InvalidCharError):
            validate_python_var_name(value)

    @pytest.mark.parametrize(["value", "expected"], [
        [None, ValueError],
        ["", NullNameError],
        ["123", ValueError],
        [1, TypeError],
        [True, TypeError],
    ])
    def test_exception_type(self, value, expected):
        with pytest.raises(expected):
            validate_python_var_name(value)

    @pytest.mark.parametrize(["value", "expected"], [
        [reserved_keyword, InvalidReservedNameError]
        for reserved_keyword in RESERVED_KEYWORDS + ["__debug__"]
    ])
    def test_exception_reserved(self, value, expected):
        with pytest.raises(expected):
            validate_python_var_name(value)


class Test_sanitize_python_var_name:
    SANITIZE_CHAR_LIST = INVALID_PYTHON_VAR_CHARS
    NOT_SANITIZE_CHAR_LIST = ["_"]
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
        sanitized_name = sanitize_python_var_name(value, replace_text)
        assert sanitized_name == expected
        validate_python_var_name(sanitized_name)

    @pytest.mark.parametrize(["value", "expected"], [
        ["a!あ#い$b%う%え&c'お", "aあいbうえcお"],
    ])
    def test_normal_multibyte(self, value, expected):
        sanitize_ltsv_label(value)

    @pytest.mark.parametrize(
        ["value", "replace_text", "expected"],
        [
            [invalid_char + "hoge_123", "_", "hoge_123"]
            for invalid_char in string.digits + "_"
        ] + [
            [invalid_char + "hoge_123", "a", "ahoge_123"]
            for invalid_char in string.digits + "_"
        ]
    )
    def test_normal_invalid_first_char_x1(self, value, replace_text, expected):
        sanitized_name = sanitize_python_var_name(value, replace_text)
        assert sanitized_name == expected
        validate_python_var_name(sanitized_name)

    @pytest.mark.parametrize(
        ["value", "replace_text", "expected"],
        [
            [invalid_char * 2 + "hoge_123", "_", "hoge_123"]
            for invalid_char in string.digits + "_"
        ] + [
            [invalid_char * 2 + "hoge_123", "a", "aahoge_123"]
            for invalid_char in string.digits + "_"
        ]
    )
    def test_normal_invalid_first_char_x2(self, value, replace_text, expected):
        sanitized_name = sanitize_python_var_name(value, replace_text)
        assert sanitized_name == expected
        validate_python_var_name(sanitized_name)

    @pytest.mark.parametrize(["value", "expected"], [
        [reserved_keyword, reserved_keyword + "_"]
        for reserved_keyword in RESERVED_KEYWORDS
    ])
    def test_normal_reserved(self, value, expected):
        assert sanitize_python_var_name(value) == expected

    @pytest.mark.parametrize(["value", "expected"], [
        [None, ValueError],
        [1, TypeError],
        [True, TypeError],
    ])
    def test_exception_type(self, value, expected):
        with pytest.raises(expected):
            sanitize_python_var_name(value)
