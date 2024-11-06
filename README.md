Attempt to create a minimal EDK2 for Samsung Galaxy J1.

## Status
-

## Building
Tested on Ubuntu 22.04.

First, clone EDK2.

```
cd ..
git clone https://github.com/tianocore/edk2.git -b edk2-stable202405 --recursive
git clone https://github.com/tianocore/edk2-platforms.git
```

You should have all three directories side by side.

Next, install dependencies:

20.04 or later:

```
sudo apt install build-essential uuid-dev iasl git nasm python3-distutils crossbuild-essential-armel
```

Also see [EDK2 website](https://github.com/tianocore/tianocore.github.io/wiki/Using-EDK-II-with-Native-GCC#Install_required_software_from_apt)

Then ./scripts/firstrun.sh

Finally, "./scripts/j13g.sh" to compile.

Then make a Image from AIK (Android Image Kitchen) and rename image-new.img to boot.img and make a tar for odin.

Finally, flash it with Odin.

# Credits

SimpleFbDxe screen driver is from imbushuo's [Lumia950XLPkg](https://github.com/WOA-Project/Lumia950XLPkg).

Based on sonic011gamer [edk2-msm8909](https://github.com/sonic011gamer/edk2-msm8909) and on vicenteicc2008 [edk2-goyavewifi](https://github.com/vicenteicc2008/edk2-goyavewifi).

SprdGpioDxe driver is from halal-beef's [edk2-exynos9830](https://github.com/halal-beef/edk2-exynos9830).