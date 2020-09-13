#pragma once
#ifdef EXPORT
#define PROC_API// __declspec(dllexport)
#else
#define PROC_API //__declspec(dllimport)
#endif