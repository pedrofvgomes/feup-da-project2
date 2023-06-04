#include "menu/menu.cpp"

int main(){
    Menu menu;
    while(menu.getState() != -1)
        menu.drawState();
    return 0;
}