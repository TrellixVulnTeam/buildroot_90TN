**DataProperty**

.. image:: https://badge.fury.io/py/DataProperty.svg
    :target: https://badge.fury.io/py/DataProperty

.. image:: https://img.shields.io/travis/thombashi/DataProperty/master.svg?label=Linux
    :target: https://travis-ci.org/thombashi/DataProperty

.. image:: https://img.shields.io/appveyor/ci/thombashi/dataproperty/master.svg?label=Windows
    :target: https://ci.appveyor.com/project/thombashi/dataproperty

.. image:: https://coveralls.io/repos/github/thombashi/DataProperty/badge.svg?branch=master
    :target: https://coveralls.io/github/thombashi/DataProperty?branch=master

    
.. contents:: Table of contents
   :backlinks: top
   :local:


Summary
=======
A Python library for extract property from data.


Installation
============

::

    pip install DataProperty


Usage
=====

Extract property of data
------------------------

e.g. Extract a ``float`` value property
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. code:: python

    >>> from dataproperty import DataProperty
    >>> DataProperty(-1.1)
    data=-1.1, typename=REAL_NUMBER, align=right, ascii_char_width=4, integer_digits=1, decimal_places=1, additional_format_len=1

e.g. Extract a ``int`` value property
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. code:: python

    >>> from dataproperty import DataProperty
    >>> DataProperty(123456789)
    data=123456789, typename=INTEGER, align=right, ascii_char_width=9, integer_digits=9, decimal_places=0, additional_format_len=0

e.g. Extract a ``str`` (ascii) value property
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. code:: python

    >>> from dataproperty import DataProperty
    >>> DataProperty("sample string")
    data=sample string, typename=STRING, align=left, length=13, ascii_char_width=13, additional_format_len=0

e.g. Extract a ``str`` (multi-byte) value property
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. code:: python

    >>> import six
    >>> from dataproperty import DataProperty
    >>> six.text_type(DataProperty("吾輩は猫である"))
    data=吾輩は猫である, typename=STRING, align=left, length=7, ascii_char_width=14, additional_format_len=0

e.g. Extract a time (``datetime``) value property
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. code:: python

    >>> import datetime
    >>> from dataproperty import DataProperty
    >>> DataProperty(datetime.datetime(2017, 1, 1, 0, 0, 0))
    data=2017-01-01 00:00:00, typename=DATETIME, align=left, ascii_char_width=19, additional_format_len=0

e.g. Extract a ``bool`` value property
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. code:: python

    >>> from dataproperty import DataProperty
    >>> DataProperty(True)
    data=True, typename=BOOL, align=left, ascii_char_width=4, additional_format_len=0


Extract data property for each element from a matrix
----------------------------------------------------
``DataPropertyExtractor.to_dp_matrix`` method returns a matrix of ``DataProperty`` instances from a data matrix. 
An example data set and the result are as follows:

:Sample Code:
    .. code:: python
    
        import datetime
        from dataproperty import DataPropertyExtractor

        dp_extractor = DataPropertyExtractor()
        dt = datetime.datetime(2017, 1, 1, 0, 0, 0)
        inf = float("inf")
        nan = float("nan")

        dp_matrix = dp_extractor.to_dp_matrix([
            [1, 1.1, "aa", 1, 1, True, inf, nan, dt],
            [2, 2.2, "bbb", 2.2, 2.2, False, "inf", "nan", dt],
            [3, 3.33, "cccc", -3, "ccc", "true", inf, "NAN", "2017-01-01T01:23:45+0900"],
        ])

        for row, dp_list in enumerate(dp_matrix):
            for col, dp in enumerate(dp_list):
                print("row={:d}, col={:d}, {}".format(row, col, str(dp)))

:Output:
    ::

        row=0, col=0, data=1, typename=INTEGER, align=right, ascii_char_width=1, integer_digits=1, decimal_places=0, additional_format_len=0
        row=0, col=1, data=1.1, typename=REAL_NUMBER, align=right, ascii_char_width=3, integer_digits=1, decimal_places=1, additional_format_len=0
        row=0, col=2, data=aa, typename=STRING, align=left, ascii_char_width=2, length=2, additional_format_len=0
        row=0, col=3, data=1, typename=INTEGER, align=right, ascii_char_width=1, integer_digits=1, decimal_places=0, additional_format_len=0
        row=0, col=4, data=1, typename=INTEGER, align=right, ascii_char_width=1, integer_digits=1, decimal_places=0, additional_format_len=0
        row=0, col=5, data=True, typename=BOOL, align=left, ascii_char_width=4, additional_format_len=0
        row=0, col=6, data=Infinity, typename=INFINITY, align=left, ascii_char_width=8, additional_format_len=0
        row=0, col=7, data=NaN, typename=NAN, align=left, ascii_char_width=3, additional_format_len=0
        row=0, col=8, data=2017-01-01 00:00:00, typename=DATETIME, align=left, ascii_char_width=19, additional_format_len=0
        row=1, col=0, data=2, typename=INTEGER, align=right, ascii_char_width=1, integer_digits=1, decimal_places=0, additional_format_len=0
        row=1, col=1, data=2.2, typename=REAL_NUMBER, align=right, ascii_char_width=3, integer_digits=1, decimal_places=1, additional_format_len=0
        row=1, col=2, data=bbb, typename=STRING, align=left, ascii_char_width=3, length=3, additional_format_len=0
        row=1, col=3, data=2.2, typename=REAL_NUMBER, align=right, ascii_char_width=3, integer_digits=1, decimal_places=1, additional_format_len=0
        row=1, col=4, data=2.2, typename=REAL_NUMBER, align=right, ascii_char_width=3, integer_digits=1, decimal_places=1, additional_format_len=0
        row=1, col=5, data=False, typename=BOOL, align=left, ascii_char_width=5, additional_format_len=0
        row=1, col=6, data=Infinity, typename=INFINITY, align=left, ascii_char_width=8, additional_format_len=0
        row=1, col=7, data=NaN, typename=NAN, align=left, ascii_char_width=3, additional_format_len=0
        row=1, col=8, data=2017-01-01 00:00:00, typename=DATETIME, align=left, ascii_char_width=19, additional_format_len=0
        row=2, col=0, data=3, typename=INTEGER, align=right, ascii_char_width=1, integer_digits=1, decimal_places=0, additional_format_len=0
        row=2, col=1, data=3.33, typename=REAL_NUMBER, align=right, ascii_char_width=4, integer_digits=1, decimal_places=2, additional_format_len=0
        row=2, col=2, data=cccc, typename=STRING, align=left, ascii_char_width=4, length=4, additional_format_len=0
        row=2, col=3, data=-3, typename=INTEGER, align=right, ascii_char_width=2, integer_digits=1, decimal_places=0, additional_format_len=1
        row=2, col=4, data=ccc, typename=STRING, align=left, ascii_char_width=3, length=3, additional_format_len=0
        row=2, col=5, data=True, typename=BOOL, align=left, ascii_char_width=4, additional_format_len=0
        row=2, col=6, data=Infinity, typename=INFINITY, align=left, ascii_char_width=8, additional_format_len=0
        row=2, col=7, data=NaN, typename=NAN, align=left, ascii_char_width=3, additional_format_len=0
        row=2, col=8, data=2017-01-01T01:23:45+0900, typename=STRING, align=left, ascii_char_width=24, length=24, additional_format_len=0


Full example source code can be found at *examples/py/to_dp_matrix.py*


Extract property for each column from a matrix
------------------------------------------------------
``DataPropertyExtractor.to_column_dp_list`` method returns a list of ``DataProperty`` instances from a data matrix. The list represents the properties for each column.
An example data set and the result are as follows:

Example data set and result are as follows:

:Sample Code:
    .. code:: python

        import datetime
        from dataproperty import DataPropertyExtractor

        dp_extractor = DataPropertyExtractor()
        dt = datetime.datetime(2017, 1, 1, 0, 0, 0)
        inf = float("inf")
        nan = float("nan")

        data_matrix = [
            [1, 1.1,  "aa",   1,   1,     True,   inf,   nan,   dt],
            [2, 2.2,  "bbb",  2.2, 2.2,   False,  "inf", "nan", dt],
            [3, 3.33, "cccc", -3,  "ccc", "true", inf,   "NAN", "2017-01-01T01:23:45+0900"],
        ]
        
        dp_extractor.header_list = [
            "int", "float", "str", "num", "mix", "bool", "inf", "nan", "time"]
        col_dp_list = dp_extractor.to_column_dp_list(dp_extractor.to_dp_matrix(dp_matrix))

        for col_idx, col_dp in enumerate(col_dp_list):
            print(str(col_dp))

:Output:
    ::

    column=0, typename=INTEGER, align=right, ascii_char_width=3, bit_length=2, integer_digits=(min=1, max=1), decimal_places=(min=0, max=0)
    column=1, typename=REAL_NUMBER, align=right, ascii_char_width=5, integer_digits=(min=1, max=1), decimal_places=(min=1, max=2)
    column=2, typename=STRING, align=left, ascii_char_width=4
    column=3, typename=REAL_NUMBER, align=right, ascii_char_width=4, integer_digits=(min=1, max=1), decimal_places=(min=0, max=1), additional_format_len=(min=0, max=1)
    column=4, typename=STRING, align=left, ascii_char_width=3, integer_digits=(min=1, max=1), decimal_places=(min=0, max=1)
    column=5, typename=BOOL, align=left, ascii_char_width=5
    column=6, typename=INFINITY, align=left, ascii_char_width=8
    column=7, typename=NAN, align=left, ascii_char_width=3
    column=8, typename=STRING, align=left, ascii_char_width=24

Full example source code can be found at *examples/py/to_column_dp_list.py*


Dependencies
============
Python 2.7+ or 3.4+

- `logbook <http://logbook.readthedocs.io/en/stable/>`__
- `typepy <https://github.com/thombashi/typepy>`__

Test dependencies
-----------------
- `pytest <https://pypi.python.org/pypi/pytest>`__
- `pytest-runner <https://pypi.python.org/pypi/pytest-runner>`__
- `tox <https://pypi.python.org/pypi/tox>`__
