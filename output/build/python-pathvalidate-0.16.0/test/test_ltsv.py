# encoding: utf-8

"""
.. codeauthor:: Tsuyoshi Hombashi <tsuyoshi.hombashi@gmail.com>
"""

from __future__ import absolute_import
from __future__ import unicode_literals

import itertools

from pathvalidate import *
import pytest

from ._common import (
    alphanum_char_list,
    INVALID_WIN_FILENAME_CHARS
)


VALID_LABEL_CHARS = alphanum_char_list + ["_", ".", "-"]
INVALID_LABEL_CHARS = INVALID_WIN_FILENAME_CHARS + [
    "!", "#", "$", '&', "'",
    "=", "~", "^", "@", "`", "[", "]", "+", ";", "{", "}",
    ",", "(", ")", "%",
    " ", "\t", "\n", "\r", "\f", "\v",
]


class Test_validate_ltsv_label:
    VALID_CHAR_LIST = alphanum_char_list
    INVALID_CHAR_LIST = INVALID_LABEL_CHARS

    @pytest.mark.parametrize(["value"], [
        ["abc" + valid_char + "hoge123"]
        for valid_char in VALID_CHAR_LIST
    ])
    def test_normal(self, value):
        validate_ltsv_label(value)

    @pytest.mark.parametrize(["value"], [
        ["abc" + invalid_char + "hoge123"]
        for invalid_char in INVALID_CHAR_LIST
    ] + [
        ["あいうえお"],
        ["ラベル"],
    ])
    def test_exception_invalid_char(self, value):
        with pytest.raises(InvalidCharError):
            validate_ltsv_label(value)


class Test_sanitize_ltsv_label:
    TARGET_CHAR_LIST = INVALID_LABEL_CHARS
    NOT_TARGET_CHAR_LIST = alphanum_char_list
    REPLACE_TEXT_LIST = ["", "_"]

    @pytest.mark.parametrize(
        ["value", "replace_text", "expected"],
        [
            ["A" + c + "B", rep, "A" + rep + "B"]
            for c, rep in itertools.product(
                TARGET_CHAR_LIST, REPLACE_TEXT_LIST)
        ] + [
            ["A" + c + "B", rep, "A" + c + "B"]
            for c, rep in itertools.product(
                NOT_TARGET_CHAR_LIST, REPLACE_TEXT_LIST)
        ]
    )
    def test_normal(self, value, replace_text, expected):
        assert sanitize_ltsv_label(value, replace_text) == expected

    @pytest.mark.parametrize(["value", "expected"], [
        ["aあいbうえcお", "abc"],
    ])
    def test_normal_multibyte(self, value, expected):
        sanitize_ltsv_label(value)

    @pytest.mark.parametrize(["value", "expected"], [
        ["", NullNameError],
        [None, NullNameError],
        [1, TypeError],
        [True, TypeError],
    ])
    def test_abnormal(self, value, expected):
        with pytest.raises(expected):
            sanitize_ltsv_label(value)
