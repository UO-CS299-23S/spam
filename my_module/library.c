#include <Python.h>

// Function to multiply two numbers
static PyObject* my_multiply(PyObject* self, PyObject* args) {
    int a, b;

    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }

    int result = a * b;
    return Py_BuildValue("i", result);
}

// Module methods table
static PyMethodDef MyModuleMethods[] = {
        {"multiply", my_multiply, METH_VARARGS, "Multiply two integers"},
        {NULL, NULL, 0, NULL}
};

// Module definition struct
static struct PyModuleDef my_module = {
        PyModuleDef_HEAD_INIT,
        "my_module",
        NULL,
        -1,
        MyModuleMethods
};

// Module initialization function
PyMODINIT_FUNC PyInit_my_module(void) {
    return PyModule_Create(&my_module);
}