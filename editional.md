---
title: TPR#17 題解
tags: 題解
type: slide
slideOptions:        # 簡報相關的設定
  theme: solarized   # 顏色主題
  transition: 'slide'
  transitionSpeed: 'fast'
---
<style>
.reveal .slides {
    font-size: 32px;
}
</style>
# NHDK TPR #17 
(Div.1+2, Sponsored by YTP)

題解


---

## 特別感謝

----

### AA 競程
![](https://i.imgur.com/Xn4lg5v.png)


----

### YTP 少年圖靈計畫
![](https://i.imgur.com/NLjITye.png)


----

### 驗題者們
sam571128、franklee1015、btlllbill、dreamoon、littlecube、Fysty、SFeather、wcwu、Darren、user1519、KTK2538、amano_hina

---

## A
### [Colten 的撞球對決記 (Pool)](https://codeforces.com/group/H0qY3QmnOW/contest/376232/problem/A)
AC: 38
First Kill: Paul Liao


----

給定兩隊的隊員
球第 $q$ 次是誰上場

----

子題 1 (20)：$n+m = 2$

----

判斷奇偶，奇數就是第一隊，反之第二隊

----

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/A.%20Pool/Koying_sub1.cpp)

----

子題 2 (80)：無額外限制

----

將只有一人的隊伍變成有兩個一樣的隊員
然後判斷兩次奇偶

----

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/A.%20Pool/Koying.cpp)

---

## B
### [豪邁大笑的Koying (Laughing Koying)](https://codeforces.com/group/H0qY3QmnOW/contest/376232/problem/B)
AC: 39
First Kill: Paul Liao

----

給笑點、接收到的好笑指數及好笑指數門檻
求豪邁大笑的時間

----

子題 1 (30)：$k=0$

----

對接收到的好笑指數做前綴和
若超過笑點就歸零並記錄時間

----

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/B.%20Laughing%20Koying/Koying_sub1.cpp)

----

子題 2 (70)：無額外限制

----

一樣做前綴和，但是改為 $\ge k$ 才加

----

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/B.%20Laughing%20Koying/Koying.cpp)

---

## C
### [Coding 夢之國的付錢問題 (Coin)](https://codeforces.com/group/H0qY3QmnOW/contest/376232/problem/C)
AC: 12
First Kill: Paul Liao

----

最大可以交易兩倍的價錢
問最少的硬幣交易量

----

子題 1 (40)：$d_{i-1}\mid d_i$

----

使用貪心法
建出 $\le 2p$ 所需的最少硬幣數量表
最後枚舉 Jack 付的價錢

時間複雜度：$O(np)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/C.%20Coin/Koying_sub1.cpp)

----

子題 2 (60)：無額外限制

----

經典的硬幣問題
使用 DP 建出 $\le 2p$ 所需的最少硬幣數量表
最後枚舉 Jack 所付的價錢，找到最後的答案

時間複雜度：$O(np)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/C.%20Coin/Koying.cpp)

---

## D
### [Coding 夢之國的過年分配問題 (New Year)](https://codeforces.com/group/H0qY3QmnOW/contest/376232/problem/D)
AC: 10
First Kill: Paul Liao

----

二分圖塗色問題

----

子題 1 (13)：$n \le 20$,
若可以使每一家都團圓,那麼總統規劃的一定是最佳方案

----


若可成功團圓則一定是最佳方案，因此只需要判斷是否為二分圖
並利用邊所連接的兩點是否分配到不同數字來驗證二分圖

時間複雜度：$O(m)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/D.%20New%20Year/Koying_sub13.cpp)

----

子題2 (27)：$n \le 20$

----

利用二元枚舉，枚舉每個家庭分配到 $0/1$
判斷是否為二分圖之後，再跟總統規劃的方案比較
找到最佳的方案

時間複雜度 $O(2^n\times m)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/D.%20New%20Year/Koying_sub12.cpp)

----

子題 3(18)
若可以使每一家都團圓,那麼總統規劃的一定是最佳方案

----

同子題 1

時間複雜度 $O(m)$

----

子題 4(42)：無額外限制

----

在同一個連通塊中，合法的二分途圖色方法只有兩種
因此我們對於每個連通塊都 DFS 一次
若每個連通塊其中一種塗色方法與總統分配的差為 $cnt$
那麼這個連通塊的最少更改數量就是 $\min(cnt, 點的數量-cnt)$

將每個連通塊的最少數量相加就是最後的答案

時間複雜度：$O(m)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/D.%20New%20Year/Koying.cpp)


---

## E
### [Koying 的彈跳床飛行記 (Flying Koying)](https://codeforces.com/group/H0qY3QmnOW/contest/376232/problem/E)
AC: 6
First Kill: Paul Liao

----

在 $1$ ~ $n-1$ 中最多選 $k$ 個點，點與點之間最多不能超過 $r$
求最大總和

----

子題 1 (15)：
$r = n, n \le 500$

----

訂狀態 $dp[i][j]$ 為跳了 $i$ 次並落地在 $j$ 的最大快樂指數總和
則 $\displaystyle dp[i][j] = \max_{l < j}(dp[i - 1][l] + h[l])$

每次轉移 $O(n)$
時間複雜度 $O(n^2k)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/E.%20Flying%20Koying/Koying_sub1.cpp)

----

子題 2 (35)：
$r=n$

----

基於子題 1 的 DP 式
我們可以利用前綴 DP 將其優化
將 $dp[i][j]$ 訂為跳了 $i$ 次並落地不遠於 $j$ 的最大快樂指數總和

如此一來，我們的 DP 轉移式就會變成
$dp[i][j] = \max(dp[i][j - 1], dp[i - 1][j - 1] + h[j - 1])$

時間複雜度 $O(nk)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/E.%20Flying%20Koying/Koying_sub2.cpp)

----

但實際上

前兩子題只要從 $h[1]$ ~ $h[n - 1]$ 中挑前 $k$ 大的
將其相加就是答案了

時間複雜度 $O(nlogn)$

不過大家可以用前兩個子題來練習一下自己的 DP ouobbb


----

子題 3 (11)：
$n \le 500$

----

套用子題 $1$ 的 DP 式
$dp[i][j]$ 為跳了 $i$ 次並落地在 $j$ 的最大快樂指數總和
但是這次的轉移式不是 $\displaystyle dp[i][j] = \max_{l < j}(dp[i - 1][l] + h[l])$ 了

由於 $r$ 的限制，所以我們只能從 $j - r$ ~ $j - 1$ 跳過來
因此轉移式為 $\displaystyle dp[i][j] = \max_{j-r \le l < j}(dp[i - 1][l] + h[l])$

時間複雜度 $O(n^2k)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/E.%20Flying%20Koying/Koying_sub13.cpp)

----

子題 4 (39)：
無額外限制

----

因為 $r$ 有限制，因此不能像子題 2 一樣用前綴 DP
這時候觀察我們的 DP 轉移式
$\displaystyle dp[i][j] = \max_{j-r \le l < j}(dp[i - 1][l] + h[l])$
看到區間最大值，不知道各位會聯想到什麼

----

線段樹？

不，我才不是 Colten

----

這題的滿分需要用到單調佇列 monotonic queue 來優化

時間複雜度 $O(nk)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/E.%20Flying%20Koying/Koying.cpp)

---

## F
### [Colten 的科學展覽會 (Science Fair)](https://codeforces.com/group/H0qY3QmnOW/contest/376232/problem/F)
AC: 5
First Kill: Paul Liao

----

求最長、長度相同且相似程度 $\ge 90\%$ 的子字串長度

----

子題 1 (19)：
$n = m = 10$

----

判斷兩個字串不一樣的字母有幾個
若 $> 1$ 那答案就是 $-1$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/F.%20Science%20Fair/Koying_sub1.cpp)

----

子題 2 (37)：
$n, m \le 30$

----

枚舉開頭、長度
找出最長的相似程度 $\ge 90\%$ 的子字串

時間複雜度 $O(n^5)$

----

子題 4 (44)：
無額外限制

----

可以發現到
我們在做編輯距離的時候
若我們做到長度 $n$
那麼在 DP 表格中就含有長度為 $1$ ~ $n$ 的編輯距離了
因此可以把枚舉長度的步驟省略

時間複雜度 $O(n ^ 4)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/F.%20Science%20Fair/Koying.cpp)


---

## G
### [高乘載管制 (High‐occupancy vehicle)](https://codeforces.com/group/H0qY3QmnOW/contest/376232/problem/G)
AC: 0

真 防破台

----

子題 1 (1)：
題目範例

----

因為我不會輸出
所以出一個子題讓我練習輸出

----

子題 2 (13)：
$N, M, K \le 5$

----

因為我不會 Debug
所以出一個子題讓我 Debug

----

子題 3 (27)：
$K = 0$

----

因為我不會 Dijkstra
所以出一個子題讓我練習 Dijkstra

時間複雜度：$O(n + mlogn)$

----

子題 4 (21)：
$K = 1$

----

因為我不會建虛點
所以出一個子題讓我練習建虛點

時間複雜度：$O(n + mlogn)$
建虛點空間複雜度：$O(mK^2)$

----

子題 5 (25)：
$K \le 10$

----

空間爆炸，我很勇
我用 priority_queue 裝

將使用了幾次折價券合併入 pq 的狀態中
省去建虛點的步驟

時間複雜度：$O(n + 10mlogn)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/G.%20High-occupancy%20vehicle/Koying_sub12345.cpp)

----

子題 6 (13)：
無額外限制

----

priority_queue 也爆炸，沒關係
早上好 Ten Point Round，現在我有兩個 D
Dijkstra 與 Dynamic Programming

----

做 $k + 1$ 次 Dijkstra
第 $i$ 次代表使用 $i$ 次折價券的情況

每次做完 Dijkstra 之後，枚舉 $t (t > i)$
將每個邊使用 $t-i$ 次折價券之後的邊權對使用 $t$ 次的狀態鬆弛

時間複雜度：$O(k\times(n + mlogn + mk))$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/G.%20High-occupancy%20vehicle/Koying.cpp)


---

## H
### [Coding 夢之國的大胃王 Jack (Big Stomach Jack)](https://codeforces.com/group/H0qY3QmnOW/contest/376232/problem/H)
AC: 2
First Kill: Gino

----

子題 1 (11)：
$n, q \le 1000,\ k=0$

----

暴力找就可以了

時間複雜度：$O(nq)$

----

子題 2(17)：
$n, q \le 1000$

暴力搜尋 + 修改

時間複雜度：$O(nq)$

----

子題 3 (29)
$k = 0$

----

利用單調佇列維護每個點最多可以吃到哪裡

時間複雜度：$O(n + q)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/H.%20Big%20Stomach%20Jack/Koying_sub13.cpp)

----

子題 4 (43)：
無額外限制

----

使用線段樹維護區間內最小的美味指數以及其位置
利用線段樹上二分搜，得出最多可以吃幾個食物
並利用查詢到的位置做修改

時間複雜度：$O(qloglogn)$

[參考程式](https://github.com/NHDK-Ten-Point-Round/ten-point-round-17/blob/main/solution/H.%20Big%20Stomach%20Jack/Koying.cpp)

