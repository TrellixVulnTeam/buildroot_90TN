#!/usr/bin/env python

# Project skeleton maintained at https://github.com/jaraco/skeleton

import io

import setuptools

with io.open('README.rst', encoding='utf-8') as readme:
	long_description = readme.read()

name = 'tempora'
description = 'Objects and routines pertaining to date and time (tempora)'

params = dict(
	name=name,
	use_scm_version=True,
	author="Jason R. Coombs",
	author_email="jaraco@jaraco.com",
	description=description or name,
	long_description=long_description,
	url="https://github.com/jaraco/" + name,
	packages=setuptools.find_packages(),
	include_package_data=True,
	python_requires='>=2.7',
	install_requires=[
		'six',
		'pytz',
	],
	extras_require={
		'testing': [
			'pytest>=2.8',
			'pytest-sugar',
			'backports.unittest_mock',
		],
		'docs': [
			'sphinx',
			'jaraco.packaging>=3.2',
			'rst.linker>=1.9',
		],
	},
	setup_requires=[
		'setuptools_scm>=1.15.0',
	],
	classifiers=[
		"Development Status :: 5 - Production/Stable",
		"Intended Audience :: Developers",
		"License :: OSI Approved :: MIT License",
		"Programming Language :: Python :: 2.7",
		"Programming Language :: Python :: 3",
	],
	entry_points={
		'console_scripts': [
			'calc-prorate = tempora:calculate_prorated_values',
		],
	},
)
if __name__ == '__main__':
	setuptools.setup(**params)
