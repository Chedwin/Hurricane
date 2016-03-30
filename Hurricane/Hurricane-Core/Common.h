#pragma once
#pragma warning (disable:4251)

#ifdef HURRICANE_PLATFORM_WINDOWS
	#ifdef HURRICANE_CORE_DLL
		#define HURRICANE_API __declspec(dllexport)
	#else
		#define HURRICANE_API __declspec(dllimport)
	#endif
#else
	#define HURRICANE_API
#endif

// Common defines
#define BIT(x) (1 << x)

#define METHOD_1(x) std::bind(x, this, std::placeholders::_1)
#define METHOD(x) METHOD_1(x)