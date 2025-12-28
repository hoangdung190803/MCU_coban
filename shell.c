//tao terminal co cac lenh co ban nhu: ls, mkdir, rm, touch, nano, ...
//khi cd ~/home/user xong ls thì nó phải hiện các file, thư mục trong folder đấy.
//tuy nhiên folder user là folder của riêng chương trình, k liên quan gì đến máy tính


#include<stdio.h> // dung cho I/O: print, fgest
#include<stdlib.h> // cap phat bo nho: malloc, free
#include<string.h> // dung de shell parse lenh


typedef enum {  // dung de tao Vtype co 2 gia tri hop le
    VFILE, VDIR // dinh nghia file ao la 0 thu muc ao la 1
} VType;

typedef struct VNode { // dinh nghia kieu du lieu moi VNode co cac thanh phan
    char name[32]; // ten file hoac folder
    VType type; // xem la file hay folder

    struct VNode* parent; // tro ve folder cha dung cho in duong dan
    struct VNode* child[32]; // folder con tro toi  co the chua toi da 32 file/folder con
    int child_count; // dem so con hien co

    char data[1024]; // luu du lieu vao file hoac folder
    
} VNode;

VNode* root; // tao ra thu muc goc
VNode* cwd; // thu muc dang lam viec
VNode* home;
// -> biet duoc duong dan va vi tri hien tai ban dang dung

void init_fs() {
    // tao root
    root = malloc(sizeof(VNode));
    strcpy(root->name, "/");
    root->type = VDIR;
    root->parent = NULL;
    root->child_count = 0;

    // tao home
    VNode* home = malloc(sizeof(VNode));
    strcpy(home->name, "home");
    home->type = VDIR;
    home->parent = root;
    home->child_count = 0;

    root->child[root->child_count++] = home; // folder con cau root khi child_count = 0 la home
                                         // root->child[0] = home (home la floder con dau tien cua root )
                                        // sau do moi xuat gia tr child_count = 1; de them folder com cho root
    // tao user: hoangdung
    VNode* HoangDung = malloc(sizeof(VNode));
    strcpy(HoangDung->name, "HoangDung");
    HoangDung->type = VDIR;
    HoangDung->parent = home;
    HoangDung->child_count = 0;

    home->child[home->child_count++] = HoangDung; // la folder con dau tien cua home

    cwd = HoangDung;
}

void cmd_ls(){ // tao lenh ls
    for(int i = 0; i< cwd->child_count; i++) {
        VNode* node = cwd->child[i];

        if (node->type == VDIR){
            printf("[DIR] %s\n", node->name);// neu la folder hien thi [DIR] TEN FOLDER
        }

        else {
            printf("[file] %s\n", node->name);
        }
    }
}

void cmd_cd(char* arg){ // kenh cd
    // cd khong co doi so
    if(arg == NULL) { // neu arg khong co nghia
        cwd = home ;
        return;
    }

    // cd /
    if (strcmp(arg, "/") == 0) {
        cwd = root;
        return;
    }

    // cd ..
    if(strcmp(arg, "..") == 0) {
        if (cwd->parent != NULL) {
            cwd = cwd->parent;
            return;
        }
    }

    // cd folder name
    for (int i = 0; i < cwd->child_count ; i++) {
        VNode*node = cwd->child[i];

        if (strcmp(node->name, arg) == 0) {
            if (node->type != VDIR) {
                printf("cd: %s is not directory\n", node->name);
                return;
            }

            cwd = node;
            return;
        
        }

    }
    // khoong tim thay file hoac dir
    printf("cd: no such file or directory: %s\n", arg);
}

void print_prompt(){ // in duong dan
    VNode* temp = cwd;
    VNode* stack[32]; // tao mang lu trong stack voi top la cac phan tu cua mang tuog ung voi thu tu cac folder
    int top=0;

    while(temp != NULL) {// di nguoc tu vi tri hien tai len root
        stack[top++] = temp;
        temp = temp->parent;
    }

    // in dong dan tu root den vi tri hien tai
    for (int i = top - 1; i >= 0; i--) {
        if(strcmp(stack[i]->name, "/") == 0){
            printf("/");

        }
        else {
            printf("%s",stack[i]->name);
            if (i != 0){
                printf("/");
            }
        }
    }
    printf("$ ");

}

void cmd_mkdir(char* name) {
    if (name == NULL){ 
        printf("mkdir: missing operand\n");
        return;
    }

    // kiemr tra co trung ten voi dolder khac khong
    for(int i = 0; i < cwd->child_count; i++) {
        if (strcmp(cwd->child[i]->name, name) == 0) {
            printf("mkdir: not create directory '%s': file exists\n",name);
            return;
        }
    }
    //  kiem tr xem full child chua
    if (cwd->child_count >= 32){
        printf("mkdir: directory is full\n");
        return;
    }

    VNode* dir = malloc(sizeof(VNode));
    strcpy(dir->name,name);
    dir->type = VDIR;
    dir->parent = cwd;
    dir->child_count = 0;

    cwd->child[cwd->child_count++] = dir;

}

void cmd_touch(char* name) {
    if (name == NULL){ 
        printf("touch: missing operand\n");
        return;
    }

    // kiemr tra co trung ten voi file khac khong
    for(int i = 0; i < cwd->child_count; i++) {
        if (strcmp(cwd->child[i]->name, name) == 0) {
            printf("touch: not create file '%s': file exists\n",name);
            return;
        }
    }
    //  kiem tra xem full child chua
    if (cwd->child_count >= 32){
        printf("touch: file is full\n");
        return;
    }

    VNode* file = malloc(sizeof(VNode));
    strcpy(file->name,name);
    file->type = VFILE;
    file->parent = cwd;
    file->child_count = 0;
    file->data[0] = '\0'; // file rong

    cwd->child[cwd->child_count++] = file;

}

void cmd_rm(char* name) {
    if (name == NULL) {
        printf("rm: missing operand\n");
        return;
    }

    for (int i = 0; i < cwd->child_count; i++) {
        VNode* node = cwd->child[i];

        if (strcmp(node->name, name) == 0) {

            // Neu la folder ma con folder con thi ko cho xoa
            if (node->type == VDIR && node->child_count > 0) {
                printf("rm: cannot remove '%s': Directory not empty\n", name);
                return;
            }

            // giai phong bo nho
            free(node); // vi ki da tao ra 1 folder hoac file ddc luu owr heap neu ko gai phong bi leak memory

            // don mang child lai
            for (int j = i; j < cwd->child_count - 1; j++) {
                cwd->child[j] = cwd->child[j + 1];
            }

            cwd->child_count--;
            return;
        }
    }

    printf("rm: cannot remove '%s': No such file or directory\n", name);
}

void cmd_nano(char* name) {
    if (name == NULL) {
        printf("nano: missing file name\n");
        return;
    }

    for (int i = 0; i < cwd->child_count; i++) {
        VNode* node = cwd->child[i];

        if (strcmp(node->name, name) == 0) {

            if (node->type != VFILE) {
                printf("nano: %s is not a file\n", name);
                return;
            }

            printf("Enter text (Ctrl+D to save):\n");
            fgets(node->data, sizeof(node->data), stdin);
            printf("\n");
            return;
        }
    }

    printf("nano: %s: No such file\n", name);
}


int main() {
    
    char input[128]; // thong tin nguoi dungf nhap vao
    char* cmd; // lenh (cd, ls touch..)
    char* arg; // doi so 

    init_fs();

    while (1) {  //taoj ra vong lap cho shell luon song
        print_prompt();
        fgets(input, sizeof(input), stdin);// in >>> va du lieu nhap tu ban phim

        cmd = strtok(input, " \n"); // tim ki tu phan cach " " hoac "\n" tra ve la \0 tu do tim ra cmd la lenh j
        arg = strtok(NULL, " \n"); // dung tiep chuoi vau tach lays ra duoc doi so

        if (!cmd) continue; // kiem tra xem nguoi dung co nhap j khong

        if (strcmp(cmd, "ls") == 0) {
            cmd_ls();
        }

        else if (strcmp(cmd,"cd") == 0){
            cmd_cd(arg);
        }

        else if (strcmp(cmd, "mkdir") == 0) {
            cmd_mkdir(arg);
        }
        
        else if (strcmp(cmd, "touch") == 0) {
            cmd_touch(arg);
        }

        else if (strcmp(cmd, "rm") == 0) {
            cmd_rm(arg);
        }

        else if (strcmp(cmd, "nano") == 0) {
            cmd_nano(arg);
        }
    }

    return 0;
}



