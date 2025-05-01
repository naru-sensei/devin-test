# devin-test

![GitHub release (latest by date)](https://img.shields.io/github/v/release/naru-sensei/devin-test)
![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/naru-sensei/devin-test/build.yml)

## 概要

このリポジトリは、GitHub Actionsを使用したCIの実装と、モバイルデバイス（iPhoneやiPad）だけでの開発が可能であることを実証するためのテストプロジェクトです。

## 機能

- C言語で「Hello, Naru Sensei!」を表示
- 「Naru Sensei」を行番号付きで100回表示
- GitHub Actionsによる自動ビルドとテスト
- PRへのビルド結果の自動コメント

## 使い方

### ローカル環境での実行

```bash
# コンパイル
gcc -o hello hello.c

# 実行
./hello
```

### GitHub Actionsについて

このプロジェクトでは、GitHub Actionsを使用して以下の機能を実装しています：

1. **自動ビルド**: PRやpushが行われると、C言語のコードが自動的にコンパイルされます
2. **自動テスト**: コンパイルされたプログラムが実行され、出力が確認されます
3. **PRコメント**: ビルド結果がPRにコメントとして自動的に投稿されます

これにより、パソコンがなくてもiPhoneやiPadだけでコードの開発とテストが可能になります。

## 開発者

- [@naru-sensei](https://github.com/naru-sensei)
- [@GOROman](https://github.com/GOROman)

## 設定

このアプリケーションは以下の設定をサポートしています：

### コマンドライン引数

```bash
./hello --greeting="こんにちは、世界！" --name="侍エンジニア" --repetitions=10
```

短いオプション形式も使用できます：

```bash
./hello -g "こんにちは、世界！" -n "侍エンジニア" -r 10
```

ヘルプメッセージを表示するには：

```bash
./hello --help
```

### 環境変数

```bash
HELLO_GREETING="こんにちは、世界！" HELLO_NAME="侍エンジニア" HELLO_REPETITIONS=10 ./hello
```

### 優先順位

設定の優先順位は次の通りです：コマンドライン引数 > 環境変数 > デフォルト値

## ライセンス

このプロジェクトはMITライセンスの下で公開されています。

## Devin.ai に興味がある方はこのリファラルからぜひ！

https://app.devin.ai/invite/ifzuUmq3YTE7oXdG

<img width="1089" alt="image" src="https://github.com/user-attachments/assets/ed846f56-963b-4f4f-92fc-0824cd38a476" />


