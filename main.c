#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

struct shaurma {
     int sh_price;
     int sh_weight;
     char *sh_type;
};

struct pizza {
    int pizza_price;
    int pizza_diameter;
    char *pizza_type;
};

struct drink {
    int drink_price;
    int drink_volume;
    char *drink_type;
};

struct soup {
    int soup_price;
    char *soup_name;
};

struct fries {
    int fries_price;
    int fries_quantity;
    char *fries_type;
};

struct basket {
    struct shaurma sh_get;
    struct pizza pizza_get;
    struct drink drink_get;
    struct fries fries_get;
    struct soup soup_get;
};

void init(struct basket *p){
    p->sh_get.sh_price = 0;
    p->sh_get.sh_weight = 0;
    p->sh_get.sh_type = (char*)calloc(30, (sizeof(char)));

    p->pizza_get.pizza_price = 0;
    p->pizza_get.pizza_diameter = 0;
    p->pizza_get.pizza_type = (char*)calloc(30, (sizeof(char)));

    p->drink_get.drink_price = 0;
    p->drink_get.drink_volume = 0;
    p->drink_get.drink_type = (char*)calloc(30, (sizeof(char)));

    p->soup_get.soup_price = 0;
    p->soup_get.soup_name = (char*)calloc(30, (sizeof(char)));

    p->fries_get.fries_price = 0;
    p->fries_get.fries_quantity = 0;
    p->fries_get.fries_type = (char*)calloc(30, (sizeof(char)));
}

void input(struct basket *p){
    int ans[5];
    printf("\nШаурма? 1/0");
    scanf("%d", &ans[0]);
    if (ans[0] == 1){
        printf("Введите вид");
        scanf("%s", p->sh_get.sh_type);
        printf("Введите вес");
        scanf("%d", &p->sh_get.sh_weight);
        printf("Введите стоимость");
        scanf("%d", &p->sh_get.sh_price);
    }
    else puts("Окей");

    printf("Пицца? 1/0 ");
    scanf("%d", &ans[1]);
    if (ans[1] == 1) {
        printf("Введите вид");
        scanf("%s", p->pizza_get.pizza_type);
        printf("Введите диаметр");
        scanf("%d", &p->pizza_get.pizza_diameter);
        printf("Введите стоимость");
        scanf("%d", &p->pizza_get.pizza_price);
    }
    else puts("Окей");

    printf("Напиток?  1/0 ");
    scanf("%d", &ans[2]);
    if (ans[2] == 1) {
        printf("Введите название");
        scanf("%s", p->drink_get.drink_type);
        printf("Введите объем");
        scanf("%d", &p->drink_get.drink_volume);
        printf("Введите стоимость");
        scanf("%d", &p->drink_get.drink_price);
    }
    else puts("Окей");

    printf("Суп?  1/0 ");
    scanf("%d", &ans[3]);
    if (ans[3] == 1) {
        printf("Введите вид");
        scanf("%s", p->soup_get.soup_name);
        printf("Введите стоимость");
        scanf("%d", &p->soup_get.soup_price);
    }
    else puts("Окей");

    printf("Фри?  1/0 ");
    scanf("%d", &ans[4]);
    if (ans[4] == 1) {
        printf("Введите вид");
        scanf("%s", p->fries_get.fries_type);
        printf("Введите количество");
        scanf("%d", &p->fries_get.fries_quantity);
        printf("Введите стоимость");
        scanf("%d", &p->fries_get.fries_price);
    }
    else puts("окей");
}

void payment(sum) {
    int way, chance, money, change;
    printf("Выерите способ оплаты карта/наличные 1/2");
    scanf("%d", &way);
    if (way == 1) {
        srand(time(NULL));
        chance = 1 + rand() % (2 - 1 + 1);
        if (chance == 1)
            printf("Отлично! Оплата прошла");
        if (chance == 2)
            printf("Не хватает средств");
    }
    if (way == 2) {
        printf("Введите отданную кассиру сумму");
        scanf("%d", &money);
        change = money - sum;
        if (change > 0)
            printf("Сдача: %d", change);
        if (change < 0)
            printf("Нужно добавить: %d", abs(change));
        if (change == 0)
            printf("Без сдачи");
    }
}

int order_res(struct basket *p) {
    int sum;
    puts("Ваш заказ:");
    if (p->sh_get.sh_price)
        printf("Вид шаурмы - %s; вес - %d; цена - %d\n", p->sh_get.sh_type, p->sh_get.sh_weight, p->sh_get.sh_price);
    if (p->pizza_get.pizza_price)
        printf("Вид пиццы - %s; диаметр - %d; цена - %d\n", p->pizza_get.pizza_type, p->pizza_get.pizza_diameter, p->pizza_get.pizza_price);
    if (p->drink_get.drink_price)
        printf("Вид напитка - %s; объем - %d; цена - %d\n", p->drink_get.drink_type, p->drink_get.drink_volume, p->drink_get.drink_price);
    if (p->soup_get.soup_price)
        printf("Название супа - %s; цена - %d\n", p->soup_get.soup_name, p->soup_get.soup_price);
    if (p->fries_get.fries_price)
        printf("Вид шаурмы - %s; количество - %d; цена - %d\n", p->fries_get.fries_type, p->fries_get.fries_quantity, p->fries_get.fries_price);

    sum = p->sh_get.sh_price + p->pizza_get.pizza_price + p->drink_get.drink_price + p->soup_get.soup_price + p->fries_get.fries_price;
    printf("Итог: %d\n", sum);
    return sum;
}

int main() {
    int sum;
    SetConsoleOutputCP(CP_UTF8);
    struct basket account;
    init(&account);
    input(&account);
    sum = order_res(&account);
    payment(sum);
}

