#include "SpecialPrinter.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

SpecialPrinter::SpecialPrinter() : START("\033["), END("\033[0m") {
    txtColors = {
        {"black", 30},
        {"red", 31},
        {"green", 32},
        {"yellow", 33},
        {"blue", 34},
        {"magenta", 35},
        {"cyan", 36},
        {"white", 37},
        {"default", 39},
        {"bright-black", 90},
        {"bright-red", 91},
        {"bright-green", 92},
        {"bright-yellow", 93},
        {"bright-blue", 94},
        {"bright-magenta", 95},
        {"bright-cyan", 96},
        {"bright-white", 97}
    };

    bgColors = {
        {"default", 49},
        {"black", 40},
        {"red", 41},
        {"green", 42},
        {"yellow", 43},
        {"blue", 44},
        {"magenta", 45},
        {"cyan", 46},
        {"white", 47},
        {"bright-black", 100},
        {"bright-red", 101},
        {"bright-green", 102},
        {"bright-yellow", 103},
        {"bright-blue", 104},
        {"bright-magenta", 105},
        {"bright-cyan", 106},
        {"bright-white", 107}
    };

    genStyles = {
        {"bold", 1},
        {"faint", 2},
        {"italic", 3},
        {"underline", 4},
        {"slow-blink", 5},
        {"rapid-blink", 6},
        {"swap-txt-bg-color", 7},
        {"hide", 8},
        {"strike-through", 9},
        {"default-font", 10},
        {"gothic", 20},
        {"double-underline", 21},
        {"normal-intensity", 22},
        {"no-italic", 23},
        {"no-underline", 24},
        {"no-blink", 25},
        {"proportional", 26},
        {"no-reverse", 27},
        {"no-hide", 28},
        {"no-strike", 29}
    };

    altFonts = {
        {"alt-font-1", 11},
        {"alt-font-2", 12},
        {"alt-font-3", 13},
        {"alt-font-4", 14},
        {"alt-font-5", 15},
        {"alt-font-6", 16},
        {"alt-font-7", 17},
        {"alt-font-8", 18},
        {"alt-font-9", 19}
    };
}

void SpecialPrinter::print(string text, string txtColor, string bgColor, FontWeight fontWeight, Italics italics) {

    string txtColor_code = to_string(txtColors[txtColor]);
    string bgColor_code = to_string(bgColors[bgColor]);
    string fontWeight_code = to_string((int)fontWeight);
    string italics_code = to_string((int)italics);

    string output = START + txtColor_code + ';' + bgColor_code + ';' + fontWeight_code + ';' + italics_code + 'm' + text + END;

    cout << output;
}

string SpecialPrinter::format(string text, string txtColor, string bgColor, FontWeight fontWeight, Italics italics) {

    string txtColor_code = to_string(txtColors[txtColor]);
    string bgColor_code = to_string(bgColors[bgColor]);
    string fontWeight_code = to_string((int)fontWeight);
    string italics_code = to_string((int)italics);

    return START + txtColor_code + ';' + bgColor_code + ';' + fontWeight_code + ';' + italics_code + 'm' + text + END;
}

void SpecialPrinter::printPNG(const string& filePath, int maxWidth, int maxHeight) {
    int width, height, channels;
    unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &channels, 3);
    
    if (!data) {
        cout << "Failed to load image: " << filePath << endl;
        return;
    }
    
    // Calculate scaling factors
    float scaleX = (float)maxWidth / width;
    float scaleY = (float)maxHeight / height;
    float scale = min(scaleX, scaleY); // Keep aspect ratio
    
    int newWidth = (int)(width * scale);
    int newHeight = (int)(height * scale);
    
    for (int y = 0; y < newHeight; y += 2) {
        for (int x = 0; x < newWidth; x++) {
            // Map scaled coordinates back to original image
            int origX = (int)(x / scale);
            int origY = (int)(y / scale);
            int origY2 = (int)((y + 1) / scale);
            
            // Clamp to image bounds
            origX = min(origX, width - 1);
            origY = min(origY, height - 1);
            origY2 = min(origY2, height - 1);
            
            int idx1 = (origY * width + origX) * 3;
            int idx2 = (origY2 * width + origX) * 3;
            
            int r1 = data[idx1], g1 = data[idx1 + 1], b1 = data[idx1 + 2];
            int r2 = data[idx2], g2 = data[idx2 + 1], b2 = data[idx2 + 2];
            
            printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm▀\033[0m", 
                   r1, g1, b1, r2, g2, b2);
        }
        cout << endl;
    }
    
    stbi_image_free(data);
}

// Global Printer
SpecialPrinter p;

// int main() {


//     p.print("Hello!", "red", "white", BOLD, YES);
//     p.printPNG("images/natImp.png", 150, 150);
//     return 0;
// }