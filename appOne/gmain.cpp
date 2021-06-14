#define _EX

#ifdef _EX
#include"libOne.h"
void gmain() {
    window(1900, 1000, 1);
    const char* filename = "assets\\map.txt";
    FILE* fp;
    fopen_s(&fp,filename,"rb");
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* map = (char*)malloc(fileSize);
    fread(map, sizeof(char), fileSize, fp);
    fclose(fp);

    int rows = 0;
    int cols = 0;
    int cut = 0;
    print((let)"filesize=" + fileSize);

    for (int i = 0; i < fileSize; i++) {
        cut++;
        if (map[i] == '\n') {
            if (rows == 0) {
                cols = cut;
            }
            else if (cols != cut) {
                WARNING(1, "—ñ”‚ª‚»‚ë‚Á‚Ä‚¢‚È‚¢", "");
            }
            rows++;
            cut = 0;
        }
    }
    if (fileSize % cols != 0){
        WARNING(1, "ÅŒã‚Ìs‚ð‰üs‚µ‚Ä‚¢‚È‚¢", "");
    }
    print((let)"rows=" + rows);
    print((let)"cols=" + cols);

    int blockImg = loadImage("assets\\block.png");
    int itemBlockImg = loadImage("assets\\item.png");


    float size = 100;
    float worldX = 0;
    int dispCols = width / size + 1;
    float endWorldX = size * (cols - 2) - width;

    while (notQuit) {
        worldX += 1;
        if (worldX >= endWorldX)worldX = endWorldX;
        clear();
        noStroke();
        fill(31, 30, 51);
        rect(0, 0, width, height);
        int startCol = worldX / size;
        int endCol = startCol + dispCols;
        for (int c = startCol; c < endCol; c++) {
            float px = -worldX + size * c;
            for (int r = 0; r < rows; r++) {
                float py = size * r;
                int idx = r * cols + c;
                if (map[idx] == 'b') {
                    image(blockImg, px, py);
                }
                if (map[idx] == 'i') {
                    image(itemBlockImg, px, py);
                }
            }
        }
    }
    free(map);
}
#endif

#ifdef _SAMPLE
#endif