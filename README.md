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

## ライセンス

このプロジェクトはMITライセンスの下で公開されています。
