# PiApproximation

円周率を指定された桁数求めます。

# Requirement

GMPがインストールされている必要があります。
# Installation

Ubuntuの場合

```bash
sudo apt install libgmp-dev
```

# Usage

```bash
./run.sh
```
このあとに求めたい桁数を入力します。小数点以下10000桁求めたいなら10000と入力してください。

# Note

10000桁と入力すると10006桁まで正確に求めます。入力した値よりわずかに多い桁数求めるのは仕様です。

# Author

constantpi(https://github.com/constantpi/)
