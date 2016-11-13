#Linux内核编译
***
##一.下载解压内核
<p>1.从官网下载所要编译的内核[kernel](https://www.kernel.org/)
<p>2.解压内核<code>tar -xf linux-*.tar.xz</code>
<p>[更多解压命令](http://blog.csdn.net/wugsh15/article/details/50394650)

<p>安装新内核注意：安装的新内核最好要高于当前linux内核的默认版本，且不要版本不要跨度太大。以免内核出现接口的不匹配情况，使内核不稳定。

##二.配置内核选项
<p>cd入linux内核文件夹。然后就可以开始配置内核选项了，但是内核选项多的真是令人发指，其实用默认的就好，跟着我的命令一起来做。
<p>make menuconfig执行这个操作如果出现报错的话，需要解决一个软件包依赖问题，输入以下命令即可解决（没出现报错的不用管）：<code>apt-get install libncurses5-dev</code>,然后会出现这样一个界面：
![Mou icon](http://www.linuxidc.com/upload/2015_10/151001164574021.png)

在这个界面里，*代表yes，空代表no，M代表模块化（被其它选项所包括），默认不去动它就好。
<p>方向键上下可以控制上下切换条目，左右键可以在下方的操作栏切换。
<p>直接切换到 <Save\> 然后敲回车即可，提示保存文件名为.config，直接敲回车 <Ok\> ，提示配置文件已写入.config，然后再敲一次回车 <Exit\> 。

![Mou icon](http://www.linuxidc.com/upload/2015_10/151001164574022.png)

##三.编译内核
上面操作全部完成之后，就可以开始make内核了。

make的时间会非常长，make -jn
(n是要衍生的作业书，在实际中，每个处理器上一般衍生一个活两个作业。例如在一个双核处理器上可以使用$make -j4)
##四.安装内核
make完成之后，就可以安装内核模块了。

make modules_install这个速度会很快完成，完成之后直接make install安装新内核。
##五.更新grub
最后更新一下grub：<code>update-grub</code>

##六.重启
在启动项内选择刚编译的新内核启动。


#Grub详解
<pre><code>1. default=0
# default后加一个数字n，表示n+1个“title”操作系统，0表示第一个“title” 的操作系统，以此类推。

2. timeout=0
# timeout表示默认的等待时间，此处设置为0表示开机后系统将自动载入默认的操作系统。

3. splashimage=(hd0,3)/boot/grub/splash.xpm.gz
# 指定GRUB引导时使用的屏幕图像文件存放的路径。

4. hiddenmenu
# 隐藏菜单选项

5. title Red Hat Enterprise Linux (2.6.32-220.e16.i686)
# title定义启动菜单项的名称，title 后面的字符串就是在菜单项上显示的选项。

6. root(hd,0)
# 设置GRUB的根分区，是/boot对应的分区或boot文件夹所在的分区。

7. kernel(linux) /vmkinuz-2.6.32-220.e16.i686 ro root=UUID=d67e208c-2791-4692-a615-c4e96b6ae355 rd_NO...... rd_NO_DM
# 指定内核文件（vmkinuz-2.6.32-220.e16.i686）与要挂载的根设备（root=UUID=d67e208c-2791-4692-a615-c4e96b6ae355） ，ro是readonly的意思。

8.initrd /initramfs-2.6.32-220.e16.i686.img
# 指定初始化内存映像盘。</code></pre>

##[Grub2](http://www.jinbuguo.com/linux/grub.cfg.html)
***
　　GRUB2在BIOS平台上的常规启动步骤是这样的：BIOS --> boot.img[MBR] --> core.img[MBR gap/embedding area/BIOS Boot Partition] --> 设置"prefix root cmdpath"环境变量 --> 加载"normal.mod"模块[同时还包括它所依赖的 terminal crypto extcmd boot gettext 模块] --> 执行"normal $prefix/grub.cfg"命令

　　GRUB2在UEFI平台上的常规启动步骤是这样的：UEFI --> core.img[BOOTX64.EFI/BOOTX86.EFI] --> 设置"prefix root cmdpath"环境变量 --> 加载"normal.mod"模块[同时还包括它所依赖的 terminal crypto extcmd boot gettext 模块] --> 执行"normal $prefix/grub.cfg"命令

　　如果上述步骤全部成功，那么你将进入'普通模式'，一般是显示一个菜单(找到了'$prefix/grub.cfg')，或者直接进入GRUB SHELL(没找到'$prefix/grub.cfg')。在普通模式中，命令模块[command.lst]与加密模块[crypto.lst]会被自动按需载入(无需使用"insmod"命令)，并且可使用完整的GRUB脚本功能。但是其他模块则可能需要明确使用"insmod"命令来载入。
***
###grub.cfg实例
<pre><code>
#由于"$prefix"的值是在"grub-install"安装时确定的，并且嵌入'core.img'中的模块也是随硬件变化的，
#所以不要只是简单的复制'grub'目录到处使用，而应该在每一个介质上都使用"grub-install"进行安装。

#################
## (1)特殊变量 ##
#################
#默认启动第一个菜单项
set default=0
#如果第一个菜单项启动失败，转而启动第二个菜单项
set fallback=1
#优先使用最常规的1024x768分辨率，以保证在不同的屏幕上拥有一致的菜单效果，如果失败再自动匹配分辨率
set gfxmode=1024x768,auto
#使用自己制作的24px的大号字体以避免默认字体太小看不清
set gfxterm_font=WenQuanYiMicroHeiMono24px
#将GRUB2设置为简体中文界面
set lang=zh_CN
#指定翻译文件(*.mo)的目录，若未明确设置此目录，则无法显示中文界面。
set locale_dir=$prefix/locale
#每一满屏后暂停输出，以免信息太多一闪而过看不清
set pager=1
#开启密码验证功能，并设置一个名为'root'的超级用户
set superusers=root
#设置菜单的超时时间为5秒
set timeout=5

#################
## (2)公共模块 ##
#################
#两种最流行的磁盘分区格式
insmod part_gpt
insmod part_msdos
#常见文件系统驱动
insmod btrfs
insmod exfat
insmod ext2
insmod fat
insmod iso9660
insmod jfs
insmod ntfs
insmod reiserfs
insmod udf
insmod xfs
insmod zfs
#一次性加载所有可用的视频驱动
insmod all_video
#图形模式终端
insmod gfxterm
#背景图片支持
insmod png

#########################################
## (3)公共命令(必须放在模块和变量之后) ##
#########################################
#激活图形模式的输出终端，以允许使用中文和背景图
terminal_output  gfxterm
#设置背景图片
background_image $prefix/themes/1024x768.png
#加载自己制作的24px的大号字体文件($prefix/fonts/WenQuanYiMicroHeiMono24px.pf2)
loadfont WenQuanYiMicroHeiMono24px
#设置'root'用户的哈希密码[通过"grub-mkpasswd-pbkdf2"工具生成]
password_pbkdf2 root grub.pbkdf2.sha512.69.7DBCA469F80EA1C0A8A1E2FEBC4F8463.B073C1C89EC1E85309C3D6A1BAFF4356

#################
## (4)菜单项   ##
#################

menuentry '正常启动(Windows)' --unrestricted {
    if [ 'pc' == $grub_platform ] ; then
        if search --file --set --no-floppy /bootmgr ; then
            chainloader +1
        elif search --file --set --no-floppy /ntldr ; then
            chainloader +1
        else
            echo '没有找到Windows'
            sleep --verbose 5
        fi
    fi

    if [ 'efi' == $grub_platform ] ; then
        if search --file --set --no-floppy /EFI/Microsoft/Boot/bootmgfw.efi ; then
            chainloader /EFI/Microsoft/Boot/bootmgfw.efi
        else
            echo '没有找到Windows'
            sleep --verbose 5
        fi
    fi
}

if [ 'pc' == $grub_platform ] ; then
    if search --file --set --no-floppy /os/WinPE.iso ; then
        menuentry '系统救援(WinPE)' --users=root {
            linux16  $prefix/memdisk iso raw
            initrd16 /os/WinPE.iso
        }
    fi
fi

#硬盘安装 Gentoo
if search --file --set --no-floppy /os/gentoo/image.squashfs ; then
    if [ -f /livecd -a -f /os/gentoo/gentoo -a -f /os/gentoo/gentoo.igz ] ; then
        menuentry 'Gentoo LiveCD' --users=root {
            linux  /os/gentoo/gentoo cdroot looptype=squashfs loop=/os/gentoo/image.squashfs rootwait doscsi nodmraid nokeymap docache dosshd scandelay slowusb passwd=123
            initrd /os/gentoo/gentoo.igz
        }
    fi
fi

#另一种硬盘安装 Gentoo 的方法
if search --file --set --no-floppy /os/install-amd64-minimal.iso ; then
    menuentry 'Mini Gentoo LiveCD' --users=root {
        loopback loop0 /os/install-amd64-minimal.iso
        linux  (loop0)/isolinux/gentoo cdroot isoboot=/os/install-amd64-minimal.iso rootwait doscsi nodmraid nokeymap docache dosshd scandelay slowusb passwd=123
        initrd (loop0)/isolinux/gentoo.igz
    }
fi

#如果要在UEFI平台上安装 Gentoo 那么可以使用基于Gentoo的SystemRescueCd以UEFI方式启动
if search --file --set --no-floppy /os/systemrescuecd.iso ; then
    menuentry 'SystemRescueCd LiveCD Standard 64bit kernel' --unrestricted {
        loopback loop0 /os/systemrescuecd.iso
        linux  (loop0)/isolinux/rescue64 isoloop=/os/systemrescuecd.iso docache setkmap=us scandelay doscsi rootpass=123
        initrd (loop0)/isolinux/initram.igz
    }
    menuentry 'SystemRescueCd LiveCD Alternative 64bit kernel' --unrestricted {
        loopback loop0 /os/systemrescuecd.iso
        linux  (loop0)/isolinux/altker64 isoloop=/os/systemrescuecd.iso docache setkmap=us scandelay doscsi rootpass=123
        initrd (loop0)/isolinux/initram.igz
    }
fi

#硬盘安装 Debian 8.6 [假定'/os/Debian.iso'所在分区的卷标是'GRUB2'][这种方法也适用于 Kali Linux 2016.2 ]
#[加上"username=root"后，桌面上的安装快捷方式会消失，需要使用"system tools -> install Debian sid"安装]
if search --file --set --no-floppy /os/Debian.iso ; then
    menuentry 'Debian 8.6 LiveCD' --users=root {
        loopback loop0 /os/Debian.iso
        linux  (loop0)/live/vmlinuz boot=live fromiso=/dev/disk/by-label/GRUB2/os/Debian.iso rootwait ro username=root
        initrd (loop0)/live/initrd.img
    }
fi

#硬盘安装 Ubuntu 16.10
#[加上"username=root"后，桌面上的安装快捷方式会消失，需要使用"system tools -> install Ubuntu"安装]
if search --file --set --no-floppy /os/Ubuntu.iso ; then
    menuentry 'Ubuntu 16.10 LiveCD amd64' --users=root {
        loopback loop0 /os/Ubuntu.iso
        linux  (loop0)/casper/vmlinuz.efi boot=casper iso-scan/filename=/os/Ubuntu.iso rootwait ro username=root
        initrd (loop0)/casper/initrd.lz
    }
fi

#硬盘安装 Fedora 24 [ISO卷标是"Fedora-WS-Live-24-1-2"]
#这里的方法也适用于 CentOS 7.2 LiveGNOME [其卷标是"CentOS-7-x86_64-LiveGNOME-1511"]
if search --file --set --no-floppy /os/Fedora.iso ; then
    menuentry 'Fedora-Workstation-Live-x86_64-24-1.2' --users=root {
        loopback loop0 /os/Fedora.iso
        linux  (loop0)/isolinux/vmlinuz rd.live.image iso-scan/filename=/os/Fedora.iso root=live:LABEL=Fedora-WS-Live-24-1-2
        initrd (loop0)/isolinux/initrd.img
    }
fi

#https://rhinstaller.github.io/anaconda/boot-options.html
if search --file --set --no-floppy /os/CentOS-7-x86_64-NetInstall-1511.iso ; then
    menuentry '网络安装 CentOS 7 x86_64 [只能用于简单网络环境，不可用于WiFi环境]' --unrestricted {
        loopback loop0 /os/CentOS-7-x86_64-NetInstall-1511.iso
        linux  (loop0)/images/pxeboot/vmlinuz ip=dhcp nameserver=223.6.6.6 inst.repo=http://mirrors.aliyun.com/centos/7/os/x86_64/  inst.lang=zh_CN.UTF-8
        initrd (loop0)/images/pxeboot/initrd.img
    }
fi

#[假定'/os/CentOS-7-x86_64-Minimal-1511.iso'所在分区的卷标是'GRUB2']
#这里的方法也适用于 CentOS-7-x86_64-DVD-1511.iso 与 CentOS-7-x86_64-Everything-1511.iso
if search --file --set --no-floppy /os/CentOS-7-x86_64-Minimal-1511.iso ; then
    menuentry '硬盘安装 CentOS 7.2 x86_64 [最小安装]' --unrestricted {
        loopback loop0 /os/CentOS-7-x86_64-Minimal-1511.iso
        linux  (loop0)/isolinux/vmlinuz  inst.repo=hd:LABEL=GRUB2:/os/CentOS-7-x86_64-Minimal-1511.iso  inst.lang=zh_CN.UTF-8
        initrd (loop0)/isolinux/initrd.img
    }
fi
</code></pre>