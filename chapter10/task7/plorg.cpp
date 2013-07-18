
#include <cstring>

#include "plorg.h"

Plorg::Plorg(char name[], int ci): m_ci(ci) {
	if(name){
		strncpy(m_name, name, m_LEN);
	}
}
