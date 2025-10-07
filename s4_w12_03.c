#include <stdio.h>

// ฟังก์ชัน doubleArray รับ pointer ของ array (int *arr) และขนาด array (size)
// จากนั้นวนลูปแก้ไขค่าใน array ทุกตัวโดยคูณด้วย 2
void doubleArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2; // arr[i] == *(arr + i) → ใช้ pointer เข้าถึงสมาชิกแล้วแก้ไขค่า
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5}; // สร้าง array a ขนาด 5 พร้อมค่าตั้งต้น
    int size = 5; // เก็บขนาดของ array

    // แสดงค่าก่อนการคูณ
    printf("Before: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]); // วนลูปพิมพ์สมาชิกของ array
    }
    printf("\n");

    // ส่ง array เข้าไปในฟังก์ชัน doubleArray
    // ที่จริงแล้ว array จะถูกส่งเป็น pointer ไปยังสมาชิกตัวแรก
    doubleArray(a, size);

    // หลังจากฟังก์ชันทำงาน ค่าใน array ถูกแก้ไขโดยตรง
    printf("After: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]); // วนลูปพิมพ์ค่าใหม่ที่ถูกคูณแล้ว
    }
    printf("\n");

    return 0;
}
/*
1. การส่ง array เข้าไปในฟังก์ชัน จะถูกส่งเป็น pointer โดยอัตโนมัติ

2. ดังนั้น การแก้ไขค่าผ่าน pointer ในฟังก์ชัน → มีผลกับ array ต้นฉบับ ใน main()

3. ในที่นี้ฟังก์ชัน doubleArray จะทำการคูณค่าใน array ทุกตัวด้วย 2

---

ใช้หลักการคือ = ถ้าส่ง array เข้าฟังก์ชัน จะสามารถแก้ไขค่าใน array ได้โดยตรงผ่าน pointer
*/