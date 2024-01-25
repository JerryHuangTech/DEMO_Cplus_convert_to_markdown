# Convert to Markdown - Chrome 擴充功能

## 簡介

「Convert to Markdown」是一款用 C++ 在 Visual Studio 中開發的擴充功能，旨在快速複製程式碼並將其轉換為 Markdown 格式，方便用戶分享程式內容。用戶僅需通過檔案右鍵選單即可輕鬆完成轉換。

## 特色

- **簡易安裝**：提供 `Setup convert to markdown.exe` 安裝檔，用戶可輕鬆安裝擴充功能。
- **右鍵選單整合**：安裝後，用戶在程式碼檔案上右鍵，選擇「轉換為 Markdown」即可。
- **剪貼簿便捷**：轉換後的 Markdown 內容，包括檔案名稱和程式碼，會自動暫存於剪貼簿中。

## 安裝指南

運行可執行檔案 `./Setup convert to markdown.exe` 進行安裝。安裝完成後，在程式碼檔案上右鍵即可看到轉換為 Markdown 的選項。

![INSTALL](./Docs/附件/Step0.png)

## 使用方法

- 在想要轉換的程式碼檔案上點擊右鍵。
- 從右鍵選單中選擇「Convert_To_Markdown」選項。
- 程式將立即處理內容，並將 Markdown 格式的文本複製到剪貼簿。
- 將 Markdown 內容粘貼到任何需要的位置。

右鍵點選功能

![右鍵點選功能](./Docs/附件/Step1.png)

貼至目標位置

![貼](./Docs/附件/Step2.png)

結果呈現

![結果](./Docs/附件/Step3.png)


## 解除安裝

請至控制台進行解除安裝或變更程式。

![移除](./Docs/附件/Step4.png)

## 技術實現

該工具採用 C++ 自定義的右鍵選單，並使用 Inno Setup，完成程式碼安裝與選單註冊。 製作安裝包，確保最終用戶能夠毫不費力地安裝工具。

## 貢獻

歡迎對工具進行改進或添加新功能的貢獻。請隨意分支存儲庫、進行更改並提交拉取請求。

## 授權

本專案採用 MIT 授權 - 詳情請見 LICENSE 檔案。
