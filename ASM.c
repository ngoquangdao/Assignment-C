#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#pragma pack(1)

struct DoiBong
{
    char madoi[6];
    char tendoi[17];
    char tenhuanluyenvien[17];
    int sotran;
    int solanthang;
    int solanhoa;
    int solanthua;
    int diem;
};

struct LichThiDau
{
    char tentrandau[36];
    char ngaythidau[12];
    char giothidau[7];
    char santhidau[17];
    char madoinha[6];
    char madoikhach[6];
};

struct DoiBong *doibong;

struct LichThiDau *lichthidau;

unsigned int soluongdoibong = 0, soluonglichthidau = 0;

void Vleague2019();
void Menuvleague2019();

void Quanlydanhsachdoibong();
void Menuquanlydanhsachdoibong();
void Xemdanhsachdoibong();
void Capnhatthongtindoibong();
void Themmoimotdoibong();

void Quanlylichthidau();
void Menuquanlylichthidau();
void Xemlichthidau();
void Taolichthidau();

void Quanlyketquathidau();

void Bangxephang();

void Nhapchuoi(char *s, int length);
char *Chuanhoachuoi(char *s);
char Luachon();
void Sapxepdiem(struct DoiBong *a, struct DoiBong *b);

void ReadFile(int *count, struct DoiBong *db);
void WriteFile(int count, struct DoiBong *db);

int main(int argc, char const *argv[])
{
    ReadFile(&soluongdoibong, doibong);
    if (soluongdoibong == 1)
    {
        doibong = malloc(1 * sizeof(doibong));
    }
    else if (soluongdoibong > 1)
    {
        doibong = realloc(doibong, soluongdoibong * sizeof(doibong));
    }

    Vleague2019();
    return 0;
}

void Menuvleague2019()
{
    printf("\n=========================================");
    printf("\n|--- CHAO MUNG DEN VOI V-LEAGUE 2019 ---|");
    printf("\n=========================================");
    printf("\n|    1. Quan ly danh sach doi bong      |");
    printf("\n|    2. Quan ly lich thi dau            |");
    printf("\n|    3. Quan ly ket qua thi dau         |");
    printf("\n|    4. Bang xep hang                   |");
    printf("\n|    0. Thoat                           |");
    printf("\n=========================================");
    printf("\n#Chon: ");
}

void Vleague2019()
{
    char c;
    do
    {
        Menuvleague2019();
        c = Luachon();
        switch (c)
        {
        case '1':
            Quanlydanhsachdoibong();
            break;

        case '2':
            Quanlylichthidau();
            break;

        case '3':
            if (soluonglichthidau > 0)
            {
                Quanlyketquathidau();
            }
            else
            {
                printf("\n#Khong co tran dau nao!");
            }
            break;

        case '4':
            if (soluongdoibong > 0)
            {
                Bangxephang();
            }
            else
            {
                printf("\n#Khong co doi bong nao!");
            }
            break;

        case '0':
            
            exit(1);
            break;

        default:
            printf("\n#Vui long chon chinh xac!");
            break;
        }

    } while (c != '0');
}

void Menuquanlydanhsachdoibong()
{
    printf("\n========================================");
    printf("\n|----- QUAN LY DANH SACH DOI BONG -----|");
    printf("\n========================================");
    printf("\n|     1. Xem danh sach doi bong        |");
    printf("\n|     2. Cap nhat thong tin doi bong   |");
    printf("\n|     3. Them moi mot doi bong         |");
    printf("\n|     0. Tro ve Menu chinh             |");
    printf("\n========================================");
    printf("\n#Chon: ");
}

void Quanlydanhsachdoibong()
{
    system("cls");
    char c;
    do
    {
        Menuquanlydanhsachdoibong();
        c = Luachon();
        switch (c)
        {
        case '1':
            if (soluongdoibong > 0)
            {
                Xemdanhsachdoibong();
            }
            else
            {
                printf("\n#Khong co doi bong nao de xem!");
            }
            break;

        case '2':
            if (soluongdoibong > 0)
            {
                Capnhatthongtindoibong();
            }
            else
            {
                printf("\n#Khong co doi bong nao de cap nhat!");
            }
            break;

        case '3':
            Themmoimotdoibong();
            break;

        case '0':
            Vleague2019();
            break;

        default:
            printf("\n#Vui long chon chinh xac!");
            break;
        }

    } while (c != '0');
}

void Xemdanhsachdoibong()
{
    printf("\n===============================================");
    printf("\n|    DANH SACH DOI BONG GIAI V-LEAGUE 2019    |");
    printf("\n===============================================");
    printf("\n| %-6s | %-15s | %-16s |", "Ma doi", "Ten doi bong", "Huan luyen vien");
    printf("\n-----------------------------------------------");

    for (int i = 0; i < soluongdoibong; i++)
    {
        printf("\n| %-6s | %-15s | %-16s |",
               (doibong + i)->madoi,
               (doibong + i)->tendoi,
               (doibong + i)->tenhuanluyenvien);
    }

    printf("\n===============================================\n");
}

void Capnhatthongtindoibong()
{
    char select;
    bool timmadoi = false;
    bool capnhat = false;
    struct DoiBong madoi;

    printf("================================================\n");
    printf("|         CAP NHAT THONG TIN DOI BONG          |\n");
    printf("================================================\n");
    printf("_  Nhap ma doi: ");
    Nhapchuoi(madoi.madoi, 6);
    strcpy(madoi.madoi, Chuanhoachuoi(madoi.madoi));

    for (int i = 0; i < soluonglichthidau; i++)
    {
        if (strcmpi(madoi.madoi, (lichthidau + i)->madoikhach) == 0 ||
            strcmpi(madoi.madoi, (lichthidau + i)->madoinha) == 0)
        {
            timmadoi = true;
        }
        else
        {
            timmadoi = false;
        }
    }

    if (timmadoi == false)
    {
        for (int i = 0; i < soluongdoibong; i++)
        {
            if (strcmpi((madoi).madoi, (doibong + i)->madoi) == 0)
            {
                printf("_  Nhap ten doi moi: ");
                Nhapchuoi(madoi.tendoi, 17);
                strcpy(madoi.tendoi, Chuanhoachuoi(madoi.tendoi));

                printf("_  Nhap ten huan luyen vien moi: ");
                Nhapchuoi(madoi.tenhuanluyenvien, 17);
                strcpy(madoi.tenhuanluyenvien, Chuanhoachuoi(madoi.tenhuanluyenvien));

                printf("\n#Ban co muon cap nhat khong?(Y/N): ");
                select = Luachon();
                strcpy(&select, Chuanhoachuoi(&select));

                do
                {
                    while (select != 'N' && select != 'Y')
                    {
                        printf("\n#Ban co muon cap nhat khong?(Y/N): ");
                        select = Luachon();
                        strcpy(&select, Chuanhoachuoi(&select));
                    }

                    if (select == 'Y')
                    {
                        strcpy((doibong + i)->tendoi, madoi.tendoi);
                        strcpy((doibong + i)->tenhuanluyenvien, madoi.tenhuanluyenvien);

                        printf("\n#Cap nhat thanh cong!");
                        printf("\n================================================");
                        Quanlydanhsachdoibong();
                    }

                } while (select != 'N');

                printf("\n#Cap nhat that bai!");
                printf("\n================================================");
                Quanlydanhsachdoibong();
                capnhat = true;
            }
        }
        if (capnhat == false)
        {
            printf("\n#Doi bong khong ton tai!");
            printf("\n================================================");
            Quanlydanhsachdoibong();
        }
    }
    if (timmadoi == true)
    {
        printf("\n#Khong the chinh sua thong tin doi bong nay!");
        printf("\n================================================");
        Quanlydanhsachdoibong();
    }
}

void Themmoimotdoibong()
{

    char select;

    if (soluongdoibong == 0)
    {
        doibong = (struct DoiBong *)malloc(1 * sizeof(struct DoiBong));
    }
    else if (soluongdoibong > 0)
    {
        doibong = (struct DoiBong *)realloc(doibong, (soluongdoibong + 1) * sizeof(struct DoiBong));
    }

    struct DoiBong madoi;

    printf("\n===========================================");
    printf("\n|          THEM MOI MOT DOI BONG          |");
    printf("\n===========================================\n");
    printf("_  Nhap ma doi: ");
    Nhapchuoi(madoi.madoi, 6);
    strcpy(madoi.madoi, Chuanhoachuoi(madoi.madoi));

    for (int i = 0; i < soluongdoibong + 1; i++)
    {
        if (strcmpi(madoi.madoi, (doibong + i)->madoi) != 0)
        {
            strcpy((doibong + soluongdoibong)->madoi, madoi.madoi);
            printf("_  Nhap ten doi: ");
            Nhapchuoi((doibong + soluongdoibong)->tendoi, 17);
            strcpy((doibong + soluongdoibong)->tendoi, Chuanhoachuoi((doibong + soluongdoibong)->tendoi));

            printf("_  Nhap ten huan luyen vien: ");
            Nhapchuoi((doibong + soluongdoibong)->tenhuanluyenvien, 17);
            strcpy((doibong + soluongdoibong)->tenhuanluyenvien, Chuanhoachuoi((doibong + soluongdoibong)->tenhuanluyenvien));

            (doibong + soluongdoibong)->diem = 0;
            (doibong + soluongdoibong)->solanhoa = 0;
            (doibong + soluongdoibong)->solanthang = 0;
            (doibong + soluongdoibong)->solanthua = 0;
            (doibong + soluongdoibong)->sotran = 0;
            soluongdoibong++;

            WriteFile(soluongdoibong, doibong);

            do
            {
                printf("\n#Ban muon tiep tuc?(Y/N): ");
                select = Luachon();
                strcpy(&select, Chuanhoachuoi(&select));

                while (select != 'Y' && select != 'N')
                {
                    printf("\n#Ban muon tiep tuc?(Y/N): ");
                    select = Luachon();
                    strcpy(&select, Chuanhoachuoi(&select));
                }

                if (select == 'Y')
                {
                    Themmoimotdoibong();
                }

            } while (select != 'N');

            Quanlydanhsachdoibong();
        }

        else if (strcmpi(madoi.madoi, (doibong + i)->madoi) == 0)
        {
            Quanlydanhsachdoibong();
        }
    }

    free(doibong);
}

void Menuquanlylichthidau()
{
    printf("\n========================================");
    printf("\n|-------- QUAN LY LICH THI DAU --------|");
    printf("\n----------------------------------------");
    printf("\n|     1. Xem lich thi dau              |");
    printf("\n|     2. Tao lich thi dau              |");
    printf("\n|     0. Tro ve MENU chinh             |");
    printf("\n========================================");
    printf("\n#Chon: ");
}

void Quanlylichthidau()
{

    system("cls");
    char c;
    do
    {
        Menuquanlylichthidau();
        c = Luachon();

        switch (c)
        {
        case '1':
            if (soluonglichthidau > 0)
            {
                Xemlichthidau();
            }
            else
            {
                printf("\n#Ban phai tao lich thi dau truoc!");
            }
            break;

        case '2':
            if (soluongdoibong > 1)
            {
                Taolichthidau();
            }
            else
            {
                printf("\n#Ban phai co it nhat 2 doi bong!");
            }
            break;

        case '0':
            Vleague2019();
            break;

        default:
            printf("\n#Vui long nhap chinh xac!");
            break;
        }

    } while (c != '0');
}

void Xemlichthidau()
{
    printf("\n=============================================================================");
    printf("\n|                  LICH THI DAU CUA GIAI V-LEAGUE 2019                      |");
    printf("\n=============================================================================");
    printf("\n| %-34s | %-10s | %-5s | %-15s |", "Ten tran dau", "Ngay", "Gio", "San thi dau");
    printf("\n-----------------------------------------------------------------------------");

    for (int i = 0; i < soluonglichthidau; i++)
    {
        printf("\n| %-34s | %-10s | %-5s | %-15s |",
               (lichthidau + i)->tentrandau,
               (lichthidau + i)->ngaythidau,
               (lichthidau + i)->giothidau,
               (lichthidau + i)->santhidau);
    }

    printf("\n=============================================================================\n");
}

void Taolichthidau()
{
    if (soluonglichthidau == 0)
    {
        lichthidau = (struct LichThiDau *)malloc(1 * sizeof(struct LichThiDau));
    }
    else if (soluonglichthidau > 0)
    {
        lichthidau = (struct LichThiDau *)realloc(lichthidau, (soluonglichthidau + 1) * sizeof(struct LichThiDau));
    }

    static char tentran[36], doinha[15], doikhach[15];

    printf("\n========================================");
    printf("\n|           TAO LICH THI DAU           |");
    printf("\n========================================");
    printf("\n_  Tran: ");
    Nhapchuoi(tentran, 36);
    strcpy(tentran, Chuanhoachuoi(tentran));

    for (int i = 0; i < strlen(tentran); i++)
    {
        if (tentran[i] != 'v' && tentran[i + 1] != 's')
        {
            doinha[i] = tentran[i];
        }
        else if (tentran[i] == 'v' && tentran[i + 1] == 's')
        {
            break;
        }
    }
    doinha[strlen(doinha) - 1] = '\0';
    strcpy(doinha, Chuanhoachuoi(doinha));

    for (int i = strlen(doinha) + 4; i < strlen(tentran); i++)
    {
        doikhach[i - strlen(doinha) - 4] = tentran[i];
    }
    strcpy(doikhach, Chuanhoachuoi(doikhach));

    char s;
    bool hople = false;
    int vitridoinha = 0, vitridoikhach = 0;

    for (int i = 0; i < soluongdoibong; i++)
    {
        if (strcmpi((doibong + i)->tendoi, doinha) == 0)
        {
            vitridoinha = i;

            for (int j = 0; j < soluongdoibong; j++)
            {
                if (strcmpi((doibong + j)->tendoi, doikhach) == 0)
                {
                    vitridoikhach = j;
                    hople = true;
                    break;
                }
            }
        }
    }

    if (hople == true)
    {
        strcpy((lichthidau + soluonglichthidau)->madoinha, (doibong + vitridoinha)->madoi);
        strcpy((lichthidau + soluonglichthidau)->madoikhach, (doibong + vitridoikhach)->madoi);
        strcpy((lichthidau + soluonglichthidau)->tentrandau, tentran);

        printf("_  Ngay thi dau: ");
        Nhapchuoi((lichthidau + soluonglichthidau)->ngaythidau, 12);

        printf("_  Gio thi dau: ");
        Nhapchuoi((lichthidau + soluonglichthidau)->giothidau, 7);

        printf("_  San thi dau: ");
        Nhapchuoi((lichthidau + soluonglichthidau)->santhidau, 17);
        strcpy((lichthidau + soluonglichthidau)->santhidau, Chuanhoachuoi((lichthidau + soluonglichthidau)->santhidau));

        soluonglichthidau++;

        do
        {
            printf("\n#Ban muon tiep tuc?(Y/N): ");
            s = Luachon();
            strcpy(&s, Chuanhoachuoi(&s));

            while (s != 'N' && s != 'Y')
            {
                printf("\n#Ban muon tiep tuc?(Y/N): ");
                s = Luachon();
                strcpy(&s, Chuanhoachuoi(&s));
            }

            if (s == 'Y')
            {
                Taolichthidau();
            }

        } while (s != 'N');

        Quanlylichthidau();
    }

    else
    {
        printf("\n#Doi bong khong ton tai!");
        Quanlylichthidau();
    }

    free(lichthidau);
}

void Quanlyketquathidau()
{
    system("cls");
    char s, c;
    bool hople = false;
    unsigned int diemteamhome = 0,
                 diemteamother = 0,
                 vitriteamhome = 0,
                 vitriteamother = 0;

    static char match[36], teamhome[15], teamother[15];

    printf("\n======================================");
    printf("\n|           KET QUA THI DAU          |");
    printf("\n======================================\n");
    printf("_  Nhap tran: ");
    Nhapchuoi(match, 36);
    strcpy(match, Chuanhoachuoi(match));

    for (int i = 0; i < soluonglichthidau; i++)
    {
        if (strcmpi(match, (lichthidau + i)->tentrandau) == 0)
        {
            hople = true;
            break;
        }
    }

    if (hople == false)
    {
        printf("\n#Tran dau nay khong ton tai!");
        Vleague2019();
    }

    if (hople == true)
    {
        for (int i = 0; i < strlen(match); i++)
        {
            if (match[i] != 'v' && match[i + 1] != 's')
            {
                teamhome[i] = match[i];
            }
            else if (match[i] == 'v' && match[i + 1] == 's')
            {
                break;
            }
        }
        teamhome[strlen(teamhome) - 1] = '\0';
        strcpy(teamhome, Chuanhoachuoi(teamhome));

        for (int i = strlen(teamhome) + 4; i < strlen(match); i++)
        {
            teamother[i - strlen(teamhome) - 4] = match[i];
        }
        strcpy(teamother, Chuanhoachuoi(teamother));

        do
        {
            for (int i = 0; i < soluongdoibong; i++)
            {
                if (strcmpi(teamhome, (doibong + i)->tendoi) == 0)
                {
                    vitriteamhome = i;
                    printf("_  Ket qua %s: ", teamhome);
                    fflush(stdin);
                    scanf("%d", &diemteamhome);
                    break;
                }
            }

            for (int i = 0; i < soluongdoibong; i++)
            {
                if (strcmpi(teamother, (doibong + i)->tendoi) == 0)
                {
                    vitriteamother = i;
                    printf("_  Ket qua %s: ", teamother);
                    fflush(stdin);
                    scanf("%d", &diemteamother);

                    printf("\n#Ban co muon cap nhat?(Y/N): ");
                    s = Luachon();
                    strcpy(&s, Chuanhoachuoi(&s));

                    while (s != 'N' && s != 'Y')
                    {
                        printf("\n#Ban co muon cap nhat?(Y/N): ");
                        s = Luachon();
                        strcpy(&s, Chuanhoachuoi(&s));
                    }

                    break;
                }
            }

        } while (s != 'N');
    }

    if (hople == true)
    {
        if (diemteamhome > diemteamother)
        {
            (doibong + vitriteamhome)->solanthang++;
            (doibong + vitriteamother)->solanthua++;
        }
        else if (diemteamhome < diemteamother)
        {
            (doibong + vitriteamother)->solanthang++;
            (doibong + vitriteamhome)->solanthua++;
        }
        else if (diemteamother == diemteamhome)
        {
            (doibong + vitriteamhome)->solanhoa++;
            (doibong + vitriteamother)->solanhoa++;
        }
        (doibong + vitriteamhome)->sotran++;
        (doibong + vitriteamother)->sotran++;
    }
}

void Bangxephang()
{
    system("cls");
    for (int i = 0; i < soluongdoibong; i++)
    {
        (doibong + i)->diem = (doibong + i)->solanthang * 3 + (doibong + i)->solanhoa * 2;
    }

    for (int i = 0; i < soluongdoibong - 1; i++)
    {
        for (int j = 0; j < soluongdoibong - i - 1; j++)
        {
            if ((doibong + j)->diem < (doibong + j + 1)->diem)
            {
                Sapxepdiem((doibong + j), (doibong + j + 1));
            }
        }
    }

    printf("\n===============================================================");
    printf("\n|           BANG XEP HANG GIAI BONG DA V-LEAGUE 2019          |");
    printf("\n===============================================================");
    printf("\n| %-6s | %-15s | %-4s | %-5s | %-3s | %-4s | %-4s |",
           "Ma Doi", "Ten Doi", "Tran", "Thang", "Hoa", "Thua", "Diem");
    printf("\n===============================================================");

    for (int i = 0; i < soluongdoibong; i++)
    {
        printf("\n| %-6s | %-15s | %-4d | %-5d | %-3d | %-4d | %-4d |",
               (doibong + i)->madoi,
               (doibong + i)->tendoi,
               (doibong + i)->sotran,
               (doibong + i)->solanthang,
               (doibong + i)->solanhoa,
               (doibong + i)->solanthua,
               (doibong + i)->diem);
    }

    printf("\n===============================================================");
    printf("\n...");
    printf("\n#Chuc cac doi thi dau giai V-League 2019 thanh cong!\n");
}

char *Chuanhoachuoi(char *s)
{
    while (s[0] == ' ')
    {
        strcpy(&s[0], &s[1]);
    }

    if (s[0] >= 'a' && s[0] <= 'z')
    {
        s[0] -= 32;
    }

    while (s[strlen(s) - 1] == ' ')
    {
        strcpy(&s[strlen(s) - 1], &s[strlen(s)]);
    }

    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] == ' ') && (s[i + 1] == ' '))
        {
            strcpy(&s[i], &s[i + 1]);
            i--;
        }
        if ((s[i] == ' ') && (s[i + 1] != ' '))
        {
            if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
            {
                s[i + 1] -= 32;
            }
        }
    }
    return s;
}

void Nhapchuoi(char *s, int length)
{
    fflush(stdin);
    fgets(s, length, stdin);
    s[strlen(s) - 1] = '\0';
    fflush(stdin);
}

char Luachon()
{
    char n;
    fflush(stdin);
    scanf("%c", &n);
    return n;
}

void Sapxepdiem(struct DoiBong *a, struct DoiBong *b)
{
    struct DoiBong temp = *a;
    *a = *b;
    *b = temp;
}

void ReadFile(int *count, struct DoiBong *db)
{
    FILE *f;
    f = fopen("dsdb.dat", "rb");
    if (f != NULL)
    {
        fread(count, sizeof(int), 1, f);
        if (count > 0)
        {
            fread(db,sizeof(struct DoiBong), *count, f);
        }

        fclose(f);
    }
}

void WriteFile(int count, struct DoiBong *db)
{
    FILE *f;
    f = fopen("dsdb.dat", "wb");
    if (f != NULL)
    {
        fwrite(&count, sizeof(int), 1, f);
        fwrite(db,sizeof(struct DoiBong), count, f);     
        fclose(f);
    }
}