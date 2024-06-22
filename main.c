#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "data_handler.h"
#include "system_menu.h"

int main() {
    const char* filename = "clients.csv";
    const char* filename_t = "test.csv";

    // DataHandler 초기화
    DataHandler* handler = DataHandler_Create();
    DataHandler_ReadCSV(handler, filename);

    // Display 초기화
    Display display;
    Display_Init(&display, handler);

    // 메뉴 출력
    Display_ShowMenu(&display);

    // 데이터베이스를 CSV 파일에 저장
    DataHandler_WriteCSV(handler, filename_t);

    // DataHandler 메모리를 해제
    DataHandler_Destroy(handler);

    return 0;
}