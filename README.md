# BD845-PWB IO Board

[<img src="https://img.shields.io/badge/license-CERN OHL S 2-green" />]()
[<img src="https://img.shields.io/badge/version-1.0.0-green" />]()

![BD845-PWB Front](images/bd845-pwb-front.png?raw=true)

BD845-PWB is a clone of the original Konami GN845-PWB(B) Stage I/O board for DDR machines.

[Explore the docs](https://docs.bluedotarcade.com/boards/bd845-pwb)

## About the project

The goal of the project is to replicate the original Konami GN845-PWB(B) Stage I/O board for future-proofing DDR cabinets and will work as a drop in replacement.

It emulates the original DDR Stage I/O communication protocol boot sequence allowing to run the game without an I/O Check Bypass. Other protocol features are currently not supported.

It also provides additional features such as debouncing and a Light-On-Press mode that lights up the arrow light when pressed without the need of an external lights driver board.

The board can be re-programmed with a custom/updated firmware. The latest version of the firmware can be found [here](https://github.com/bluedot-arcade/bd845-pwb-firmware).

For more information read the [docs](https://docs.bluedotarcade.com/boards/bd845-pwb).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Project structure

* [/fab/](/fab/) - the files required for fabbrication that includes gerbers, drills and assembly files.
* [/kicad/](/kicad/) -  the kicad project files.
* [/images/](/images/) - images and renders.
* [/sch_bd845-pwb-v1.0.0.pdf](/sch_bd845-pwb_v1.0.0.pdf) - the board's schematic.
* [/bom_bd845-pwb-v1.0.0.csv](/bom_bd845-pwb_v1.0.0.csv) - the board's bill of materials.
* [/ibom_bd845-pwb-v1.0.0.html](/ibom_bd845-pwb_v1.0.0.html) - an interactive bill of materials very useful for manual assembly.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Images and renders

PCB Front layer:

![BD845-PWB Front](images/bd845-pwb-front.png?raw=true)

PCB Back layer:

![BD845-PWB Back](images/bd845-pwb-back.png?raw=true)

Original Konami GN845-PWB:

![GN845-PWB Front](images/konami-gn845-pwb-front.jpg?raw=true)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## License

Distributed under the CERN OHL S 2 License. See [LICENSE.txt](/LICENSE.txt) for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Acknowledgments

* [NaokiS](http://nsaito.co.uk/) - for providing valuable information about the original DDR stage IO communication protocol.
* [Marco Ruggiero](https://www.instagram.com/ruggiero.design/) - for designing the BlueDot logo and beta-testing the board on its own cabinet.
* [InteractiveHtmlBom](https://github.com/openscopeproject/InteractiveHtmlBom) - the Kicad plugin used to generate the interactive BOM.
* [Kicad](https://www.kicad.org/) - for allowing me to design this board for free!

<p align="right">(<a href="#readme-top">back to top</a>)</p>