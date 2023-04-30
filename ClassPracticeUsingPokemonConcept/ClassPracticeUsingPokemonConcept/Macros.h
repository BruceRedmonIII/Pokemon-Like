#pragma once

#define VERBOSE_LOG(message) std::cout << message << "\n\n";

#define FILE_LOG false
#define FUNCTION_LOG false
#define LINE_LOG false

#define PRIVATE_VARIABLE_WITH_PUBLIC_GETTER_AND_SETTER(type, id) private: type m_##id; \
public: void Set##id(type value) {m_##id = value; } \
type Get##id() {return m_##id; }
