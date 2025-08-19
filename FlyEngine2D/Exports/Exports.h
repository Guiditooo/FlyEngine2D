#ifdef _WIN32
	#ifdef FLY_EXPORTS
		#define FLY_API __declspec(dllexport)
	#else
		#define FLY_API __declspec(dllimport)
	#endif
#else
	#define FLY_API __attribute__((visibility("default"))) // Para compatibilidad con otros SO
#endif