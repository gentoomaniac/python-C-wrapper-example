#include <Python.h>

#include "lib.h"

static PyObject* hello_wrapper(PyObject* self, PyObject* args)
{
  char* input;

  // parse arguments
  if (!PyArg_ParseTuple(args, "s", &input)) {
    return NULL;
  }

  // run the actual function
  hello(input);

  return NULL;
}

static PyObject* fak_wrapper(PyObject* self, PyObject* args)
{
  int num;
  int result;

  // parse arguments
  if (!PyArg_ParseTuple(args, "i", &num)) {
    return NULL;
  }

  // run the actual function
  result = fak(num);

  return Py_BuildValue("i", result);
}

static PyObject* create_dict(PyObject* self, PyObject* args)
{
  PyObject* dict = PyDict_New();
  PyObject* elementA = Py_BuildValue("i", 42);
  PyObject* elementB = PyString_FromString("what is the answer to life, the universe and everything?");

  PyDict_SetItemString(dict, "answer", elementA);
  PyDict_SetItemString(dict, "question", elementB);

  return dict;
}

static PyMethodDef HelloMethods[] = {
     { "hello", hello_wrapper, METH_VARARGS, "Say hello" },
     { "fak", fak_wrapper, METH_VARARGS, "faculty" },
     { "create_dict", create_dict, METH_VARARGS, "create sample dict" },
      { NULL, NULL, 0, NULL }
};

DL_EXPORT(void) inithello(void)
{
      Py_InitModule("hello", HelloMethods);
}
