#ifndef SPECIAL_PRINTER_H
#define SPECIAL_PRINTER_H

#include <iostream>
#include <map>

using namespace std;

enum FontWeight { FAINT=2, NORMAL=22, BOLD=1 };
enum Italics { YES=3, NO=23 };

class SpecialPrinter {
    private:
        map<string, uint8_t> txtColors;
        map<string, uint8_t> bgColors;
        map<string, uint8_t> genStyles;
        map<string, uint8_t> altFonts;


        const string START;
        const string END;

    public:
        SpecialPrinter();
        void print(string text, string txtColor = "default", string bgColor = "default", FontWeight fontWeight = NORMAL, Italics italics = NO);
        string format(string text, string txtColor = "default", string bgColor = "default", FontWeight fontWeight = NORMAL, Italics italics = NO);
        void printPNG(const string& filePath, int maxWidth = 80, int maxHeight = 24);
};

extern SpecialPrinter p;

#endif