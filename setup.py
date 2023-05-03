"""Per documentation at
https://setuptools.pypa.io/en/latest/userguide/ext_modules.html

"""

from setuptools import Extension, setup
import os
# Extension.include_dirs = ["spam"]  # NO effect

setup(
    ext_modules=[
        Extension(
            name="spam",  # as it would be imported
            # may include packages/namespaces separated by `.`
            sources=["spam/library.c"], # all sources are compiled into a single binary file
            include_dirs= [os.getcwd() + "/spam"]
        ),
    ]
)