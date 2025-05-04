#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h> // Include for printf

int main(void)
{
  // this is C, not python, but runs Piton code.
  // With GCC you need to specify the flags for python.
  // e.g: gcc main.c $(python3-config --cflags) $(python3-config --ldflags) -lpython3.10 -o main_program
  // MUST INSTALL python3-dev
  // Python config must contain proper flags check them with: python3-config --ldflags
  printf("This is C\n");
  PyStatus status;
  PyConfig config;

  PyConfig_InitIsolatedConfig(&config);
  status = PyConfig_SetString(&config, &config.program_name, L"CIntegration");
  if (PyStatus_Exception(status))
  {
    fprintf(stderr, "Error setting program name.\n");
    PyConfig_Clear(&config);
    return 1;
  }
  status = Py_InitializeFromConfig(&config);
  if (PyStatus_Exception(status))
  {
    fprintf(stderr, "Error initializing Python from config.\n");
    PyConfig_Clear(&config);
    Py_ExitStatusException(status);
    return (1);
  }
  PyConfig_Clear(&config);

  PyRun_SimpleString("print('This is Python')");
  PyRun_SimpleString("x = 'brave ' + 'sir robin'");
  PyRun_SimpleString("print(f'x = {x}')"); // Example of using the variable

  if (Py_FinalizeEx() < 0)
  {
    fprintf(stderr, "Error finalizing Python.\n");
    return 120;
  }

  printf("Python Finalized. Exiting C.\n");
  return (0);
}