"""Per documentation at
https://setuptools.pypa.io/en/latest/userguide/ext_modules.html

"""
from setuptools import setup, Extension

my_module = Extension('spam', sources=['spam/spam.c'])

setup(
    name='spam',
    version='1.0',
    description='A simple C extension module for Python',
    ext_modules=[my_module]
)
