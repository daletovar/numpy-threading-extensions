#include "Python.h"

/*
 * Some C++ compilers do not like mixin non-designated-initializers
 * like PyModuleDef_HEAD_INIT with designated-initializers like
 * .m_doc, so break this part out into a C file
 */
  

extern "C" PyObject* oldinit(PyObject *self, PyObject *args, PyObject *kwargs);
extern "C" PyObject* newinit(PyObject* self, PyObject* args, PyObject* kwargs);
extern "C" PyObject* atop_enable(PyObject * self, PyObject * args);
extern "C" PyObject* atop_disable(PyObject * self, PyObject * args);
extern "C" PyObject* atop_isenabled(PyObject * self, PyObject * args);
extern "C" PyObject* thread_enable(PyObject * self, PyObject * args);
extern "C" PyObject* thread_disable(PyObject * self, PyObject * args);
extern "C" PyObject* thread_isenabled(PyObject * self, PyObject * args);
extern "C" PyObject* thread_getworkers(PyObject * self, PyObject * args);
extern "C" PyObject* thread_setworkers(PyObject * self, PyObject * args);
extern "C" PyObject* ledger_enable(PyObject * self, PyObject * args);
extern "C" PyObject* ledger_disable(PyObject * self, PyObject * args);
extern "C" PyObject* ledger_isenabled(PyObject * self, PyObject * args);
extern "C" PyObject* ledger_info(PyObject * self, PyObject * args);
extern "C" PyObject* recycler_enable(PyObject * self, PyObject * args);
extern "C" PyObject* recycler_disable(PyObject * self, PyObject * args);
extern "C" PyObject* recycler_isenabled(PyObject * self, PyObject * args);
extern "C" PyObject* recycler_info(PyObject * self, PyObject * args);

extern "C" PyObject* timer_gettsc(PyObject * self, PyObject * args);
extern "C" PyObject* timer_getutc(PyObject * self, PyObject * args);
extern "C" PyObject* cpustring(PyObject * self, PyObject * args);

static char m_doc[] = "Provide methods to override NumPy ufuncs";


PyDoc_STRVAR(oldinit_doc,
     "oldinit(ufunc_name:");

static PyMethodDef module_functions[] = {
    {"initialize",       (PyCFunction)newinit, METH_VARARGS | METH_KEYWORDS, "init the atop"},
    {"atop_enable",      (PyCFunction)atop_enable,  METH_VARARGS, "enable the atop"},
    {"atop_disable",     (PyCFunction)atop_disable,  METH_VARARGS, "disable the atop"},
    {"atop_isenabled",   (PyCFunction)atop_isenabled,  METH_VARARGS, "returns True if atop enabled, else False"},
    {"thread_enable",    (PyCFunction)thread_enable,  METH_VARARGS, "enable worker threads"},
    {"thread_disable",   (PyCFunction)thread_disable,  METH_VARARGS, "disable worker threads"},
    {"thread_isenabled", (PyCFunction)thread_isenabled,  METH_VARARGS, "returns True if worker threads enabled else False"},
    {"thread_getworkers",(PyCFunction)thread_getworkers,  METH_VARARGS, "get the number of worker threads"},
    {"thread_setworkers",(PyCFunction)thread_setworkers,  METH_VARARGS, "set the number of worker threads, return previous value. Must be at least 1."},
    {"timer_gettsc",     (PyCFunction)timer_gettsc,  METH_VARARGS, "get the time stamp counter"},
    {"timer_getutc",     (PyCFunction)timer_getutc,  METH_VARARGS, "get the time in utc nanos since unix epoch"},
    {"cpustring",        (PyCFunction)cpustring,  METH_VARARGS, "cpu brand string plus features"},
    {"oldinit",          (PyCFunction)oldinit, METH_VARARGS | METH_KEYWORDS, oldinit_doc},
    {"ledger_enable",    (PyCFunction)ledger_enable,  METH_VARARGS, "enable ledger debuggging"},
    {"ledger_disable",   (PyCFunction)ledger_disable,  METH_VARARGS, "disable ledger"},
    {"ledger_isenabled", (PyCFunction)ledger_isenabled,  METH_VARARGS, "returns True if ledger enabled else False"},
    {"ledger_info",      (PyCFunction)ledger_info,  METH_VARARGS, "return ledger information"},
    {"recycler_enable",    (PyCFunction)recycler_enable,  METH_VARARGS, "enable recycler debuggging"},
    {"recycler_disable",   (PyCFunction)recycler_disable,  METH_VARARGS, "disable recycler"},
    {"recycler_isenabled", (PyCFunction)recycler_isenabled,  METH_VARARGS, "returns True if recycler enabled else False"},
    {"recycler_info",      (PyCFunction)recycler_info,  METH_VARARGS, "return recycler information"},
    {NULL, NULL, 0,  NULL}
};


static PyModuleDef moduledef = {
   PyModuleDef_HEAD_INIT,
   "fast_numpy_loops._fast_numpy_loops",                  // Module name
   m_doc,  // Module description
   0,
   module_functions,                     // Structure that defines the methods
   NULL,                                 // slots
   NULL,                                 // GC traverse
   NULL,                                 // GC
   NULL                                  // freefunc
};

extern "C" PyMODINIT_FUNC PyInit__fast_numpy_loops(void) {
    PyObject *module;

    module = PyModule_Create(&moduledef);

    if (module == NULL)
        return NULL;

    return module;
}
