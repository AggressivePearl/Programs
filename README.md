# Windows上配置C語言開發環境(包含git)

- Auto-generated Table of Content
[ToC]

## :memo: 安裝 Msys2
[Msys2官網](https://www.msys2.org/)  **下載完成後輸入以下指令**  

```shell
$ pacman -Syu
```
>安裝的過程中會看到  Proceed with installation? [Y/n] 打y就對了，之後執行其他指令遇到這個狀況也是相同的處理方式

**指令執行完畢後會自動關閉應用程式，請重新打開一次並輸入相同指令**

```shell
$ pacman -Syu
```

**接著執行這個指令Mingw就安裝完成啦**

```shell
$ pacman -S --needed base-devel mingw-w64-x86_64-toolchain
```

### 設定環境變數

**在這裡打*環境變數* 搜尋**

![](https://i.imgur.com/KlnHxBE.png)

**接著會出現這個畫面，點選紅色框起來的地方**

![](https://i.imgur.com/z8W9hUT.png)

**找到Path點選起來接著按下右下方的編輯按鈕**

![](https://i.imgur.com/PsLj7oe.png)

**點擊右上方的新增按鈕，輸入綠色框起來的內容。最後一直點擊*確定* 結束所有視窗**

![](https://i.imgur.com/1JBQQ2m.png)

**這樣子就完成環境變數的設定了，接著按下Win+R快捷鍵輸入cmd並按下Enter**

![](https://i.imgur.com/1OceLzW.png)

請輸入以下指令:

```shell
$ gcc --version
   ...
$ g++ --version
   ...
$ gdb --version
   ...
```

>若執行指令都出現類似以下的訊息就表示成功囉

```
gcc (Rev3, Built by MSYS2 project) 12.1.0
Copyright (C) 2022 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## :memo: 安裝 VScode

[VScode官網](https://code.visualstudio.com/)

安裝完成後，先去[我的代碼倉庫](https://github.com/AggressivePearl/Programs)下載檔案並完成解壓縮

![](https://i.imgur.com/Vy7zpqT.png)

接著開啟VScode，點選框起來的部分

![](https://i.imgur.com/OwULKzj.png)

利用搜尋欄位安裝以下插件

![](https://i.imgur.com/rBvxmZp.png)

插件安裝完後，點選<kbd>檔案</kbd>→<kbd>從檔案開啟工作區</kbd>

從剛剛解壓縮的資料夾找到 .code-workspace 結尾的檔案開啟
![](https://i.imgur.com/UvaDCJN.png)

開啟檔案後尋找hello.c點擊查看程式碼

![](https://i.imgur.com/krdyvI6.png)

點選點選<kbd>終端機</kbd>→<kbd>執行工作</kbd>，點選紅色框起的地方，因為我打開的是.c檔

![](https://i.imgur.com/yDlbPLr.png)

執行後會發現下方終端出現 hello 就表示成功了。同理，打開hello.cpp點選綠色框按鈕也會出現同樣效果。

---

### Debug

**現在要開始進行除錯(先設定好中斷點)，按下==執行並偵錯==就可以開始除錯了。**

![](https://i.imgur.com/7AYssMo.png)

**經過一番折騰，你已經可以Programs資料夾底下新建屬於你的專案進行開發了。**

## :memo: 在 VScode 中 Git 的使用

[安裝Git for Windows](https://gitforwindows.org/)

**安裝好後，進入你的GitHub頁面挑選或建立一個repository複製網址**

![](https://i.imgur.com/4oMLaEZ.png)

**接著回到VScode，選定好資料夾並打開powershell輸入：**

```shell
$ git clone <你剛剛複製的連結>
```

**接著設定**
```shell
$ git config --global user.name "你的GitHub帳號"
$ git config --global user.email "你的信箱"
```

**這樣就大功告成了**

## :memo: 以上內容的參考資料
[【網頁設計】 VS Code、Git 與 GitHub 設定教學](https://youtu.be/tO7XfKPAORM)  

[How to set up Visual Studio Code for Executing and Debugging C Programs | Tutorial](https://www.youtube.com/watch?v=r1zCtg_wqCA&ab_channel=LearningLad)  

[Msys2官網](https://www.msys2.org/)