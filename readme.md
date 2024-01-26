# ToME 2.3.5

## Tales of Middle Earth (ToME) 2.3.5 for Windows

This fork is intended to be the most stable? modern? version of the ever-popular ToME 2.3.5 that ***still includes the Alchemist*** player class.  
I'm building for Windows only so that it's easy for me to simplify code and figure out what I'm doing.

 

I've grabbed a lot of the wiki as it exits on <https://www.archive.org/>.  You can find it in the docs folder. This area could use attention.  
I'd love to find old forum posts, there was a LOT of information there on character builds and tactics.

## Install notes

I'm building this as a Cmake project in Visual Studio 2022 and using vcpkg to install dependencies. 

I found the first half of <https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-vs> useful for getting both Cmake and vcpkg up and running.

I've added a vcpkg manifest, so you can just run ```vcpkg install``` from the project root.

Edit CMakePresets.json with your own paths.


## Thanks
ToME 2.3.5 was created by darkgod at <https://te4.org/> a long time ago.  He's on version 4 now, and it's free and awesome.

[AnonymousHero](https://github.com/BardurArantsson) has done most of the modernization at <https://github.com/Tome2/Tome2>, the definitive 2.3.5 location.

Thanks to [jkatzmewing](https://github.com/jkatzmewing) for understanding what I was looking for and making a specific release available.
