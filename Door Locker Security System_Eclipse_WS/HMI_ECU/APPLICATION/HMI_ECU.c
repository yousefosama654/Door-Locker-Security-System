#include"INC/Utilities.h"
int main() {
	TASK_mainInit();
	TASK_createNewPass();
	while (1) {
		TASK_showOptions();
	}
}