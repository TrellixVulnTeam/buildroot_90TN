Developer's Overview
====================


Contributing
------------

Contribute to source code, documentation, examples and report issues on bitbucket:
https://bitbucket.org/hardbyte/python-can


Creating a Release
------------------

- Release from the ``default`` branch.
- Update the library version in ``setup.py`` and in ``doc/conf.py`` using
`semantic versioning <http://semver.org>`__.
- Run all tests and examples against available hardware.
- Update `CONTRIBUTORS.txt` with any new contributors.
- Sanity check that documentation has stayed inline with code. For large changes update ``doc/history.rst``
- Create a temporary virtual environment. Run ``python setup.py install`` and ``python setup.py test``
- Create and upload the distribution: ``python setup.py sdist bdist_wheel upload --sign``


Code Structure
--------------

The modules in ``python-can`` are:

+---------------------------------+------------------------------------------------------+
|Module                           | Description                                          |
+=================================+======================================================+
|:doc:`interfaces <interfaces>`   | Contains interface dependent code.                   |
+---------------------------------+------------------------------------------------------+
|:doc:`protocols <protocols>`     | Currently just the J1939 protocol exists here        |
+---------------------------------+------------------------------------------------------+
|:doc:`bus <bus>`                 | Contains the interface independent Bus object.       |
+---------------------------------+------------------------------------------------------+
|:doc:`CAN <api>`                 | Contains modules to emulate a CAN system, such as a  |
|                                 | time stamps, read/write streams and listeners.       |
+---------------------------------+------------------------------------------------------+
|:doc:`message <message>`         | Contains the interface independent Message object.   |
+---------------------------------+------------------------------------------------------+
|:doc:`notifier <api>`            | An object which can be used to notify listeners.     |
+---------------------------------+------------------------------------------------------+
|:doc:`broadcastmanager <bcm>`    | Contains interface independent broadcast manager     |
|                                 | code.                                                |
+---------------------------------+------------------------------------------------------+

