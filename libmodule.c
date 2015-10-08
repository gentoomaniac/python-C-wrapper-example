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

static PyMethodDef HelloMethods[] = {
     { "hello", hello_wrapper, METH_VARARGS, "Say hello" },
     { "fak", fak_wrapper, METH_VARARGS, "faculty" },
      { NULL, NULL, 0, NULL }
};

DL_EXPORT(void) inithello(void)
{
      Py_InitModule("hello", HelloMethods);
}
