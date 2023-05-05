# spam
Starter project: Reproduce the "spam" extension from Python documentation

To build the module, run
```
python setup.py build_ext --inplace
```
The command build_ext should build any module specified in ext_modules in setup, and the flag --inplace should force the .pyd or .pyc file to be created in the local folder rather than the general python installation. 