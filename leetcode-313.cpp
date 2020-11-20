/*************************************************************************
	> File Name: leetcode-313.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月09日 星期六 23时56分50秒
 ************************************************************************/
#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

typedef struct Heap {
    long long *data;
    int n, size;
} Heap;

Heap *init(int n) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->n = 0;
    h->size = n + 1;
    h->data = (long long *)malloc(sizeof(long long) * h->size);
    return h;
}

int empty(Heap *h) {
    return h->n == 0;
}

#define V(x) h->data[x]

void push(Heap *h, long long val) {
    V(++(h->n)) = val;
    int ind = h->n;
    while (ind > 1 && V(ind) < V(ind >> 1)) {
        swap(V(ind), V(ind >> 1));
        ind >>= 1;
    }
    return ;
}

long long top(Heap *h) { return V(1); }

void pop(Heap *h) {
    if (empty(h)) return ;
    V(1) = V((h->n)--);
    int ind = 1;
    while ((ind << 1) <= h->n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (V(l) < V(temp)) temp = l;
        if (r <= h->n && V(r) < V(temp)) temp = r;
        if (temp == ind) break;
        swap(V(temp), V(ind));
        ind = temp;
    }
    return ;
}

void clear(Heap *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h);
    return ;
}

int nthSuperUglyNumber(int n, int* primes, int primesSize){
    int k = primesSize;
    Heap *h = init(n * primesSize);
    push(h, 1);
    long long ans = 0;
    while (n--) {
        ans = top(h);
        pop(h);
        int i = k - 1;
        for (; i > 0; i--) {
            if (ans % primes[i]) continue;
            break;
        }
        for (int j = i; j < k; j++) {
            push(h, ans * primes[j]);
        }
    }
    clear(h);
    return ans;
}
