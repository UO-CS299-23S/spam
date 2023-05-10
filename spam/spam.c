//
// Created by jhcat on 5/3/2023.
//
#include <Python.h>
#include <stdlib.h>  // I think we need this for "system"

static PyObject *SpamError;

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    if (sts < 0) {
        PyErr_SetString(SpamError, "System command failed");
        return NULL;
    }
    return PyLong_FromLong(sts);
}

static PyMethodDef SpamMethods[] = {
        {"system",
                spam_system,
                     METH_VARARGS,
                        "Execute a shell command."},
        /* sentinel */
        {NULL, NULL, 0, NULL}
};

PyDoc_STRVAR(spam_doc, "This is direct from Python documentation");

static struct PyModuleDef spammodule = {
        PyModuleDef_HEAD_INIT,
        "spam",   /* name of module */
        spam_doc,
        // spam_doc, /* module documentation, may be NULL */
        -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
        SpamMethods
};

PyMODINIT_FUNC
PyInit_spam(void)
{
    printf("Initializing module!\n");
    PyObject *m;

    m = PyModule_Create(&spammodule);
    if (m == NULL) {
        printf("Oops, module creation failed\n");
        return NULL;
    }
    printf("Module creation succeeded!\n");

    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_XINCREF(SpamError);
    if (PyModule_AddObject(m, "error", SpamError) < 0) {
        Py_XDECREF(SpamError);
        Py_CLEAR(SpamError);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
