#define PY_SSIZE_T_CLEAN
#include <Python.h>


// Функция, вызываемая из Python
static PyObject *hello(PyObject *self, PyObject *args, PyObject *kwargs) {
	const char *name = "", *surname = "";
	char *keywords[] = {"name", "surname",NULL};
	// if (!PyArg_ParseTuple(args, "s", &name)) return NULL;
	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|ss", keywords, &name, &surname)) return NULL;
	// printf("Super Hello, %s %s!\n", name, surname);
	return Py_BuildValue("s s", name, surname);
}

static PyObject *summa(PyObject *self, PyObject *args) {
	int need_args = 2;
	PyObject *item;
	double sum = 0;
	printf("first %d elemnts not count", need_args);
	for (int i = need_args; i < PyTuple_Size(args); i++) {
		item = PyTuple_GetItem(args, i);
		sum += PyFloat_AsDouble(item);
	}
	// return Py_None;
	return Py_BuildValue("f", sum);
}

static PyObject *string(PyObject *self, PyObject *args) {
	const char *str;
	Py_ssize_t len;
	if (!PyArg_ParseTuple(args, "s#", &str, &len)) return NULL;
	char *new_str = PyMem_Malloc(sizeof(char) * (len + 1));

	for (int i = 0; i < len; i++) {
		new_str[i] = str[i];
	}
	new_str[0] = 'A';
	PyObject *result = Py_BuildValue("s#", new_str, len);
	PyMem_Free(new_str);
	return result;
}


// Таблица методов модуля
static PyMethodDef methods[] = {
	{"hello", (PyCFunction) hello, METH_VARARGS | METH_KEYWORDS, "Печатает приветствие"},
	{"summa", summa,METH_VARARGS,NULL},
	{"string", string,METH_VARARGS,NULL},
	{NULL, NULL, 0, NULL}
};

// Описание модуля
static struct PyModuleDef module = {
	PyModuleDef_HEAD_INIT,
	"hello", // Имя модуля
	NULL, // Документация
	-1, // Размер состояния модуля
	methods
};

// Инициализация модуля
PyMODINIT_FUNC PyInit_hello(void) {
	return PyModule_Create(&module);
}
