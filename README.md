<p align="right">
    <a name="readme-top"></a>
    <a href="/LICENSE.txt"><img src="https://img.shields.io/badge/license-CERN OHL S 2-green" /></a> <a href=""><img src="https://img.shields.io/badge/version-1.0.0-green" /></a> 
</p>
<br><br>
<p align="center">
    <h1 align="center">BD845-PWB IO Board</h1>
    <p align="center">A clone of the original Konami GN845-PWB(B) Stage I/O board for DDR machines.</p>
    <p align="center"><strong><a href="https://docs.bluedotarcade.com/boards/bd845-pwb">Explore the docs!</a></strong></p>
    <br><br>
</p>

<p align="center">A render of the board from the front.</p>

![BD845-PWB Front](images/bd845-pwb-front.png?raw=true)

## About the project

The goal of the project is to replicate the original Konami GN845-PWB(B) Stage I/O board by designing a drop in replacement board for future-proofing DDR cabinets.

It emulates the original DDR Stage I/O communication protocol boot sequence allowing to run the game without an I/O Check Bypass. Other protocol features are currently not supported.

It also provides additional features such as debouncing and a Light-On-Press mode that lights up the arrow light when pressed without the need of an external lights driver board.

The board can be re-programmed with a custom/updated firmware. The latest version of the firmware can be found [here](https://github.com/bluedot-arcade/bd845-pwb-firmware).

For more information read the [docs](https://docs.bluedotarcade.com/boards/bd845-pwb).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Status

The project is still in development. Don't expect all things to work just yet.
The DDR Stage IO communication protocol has not been yet implemented.

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

Distributed under the CERN OHL S 2 License. See [LICENSE.txt] for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Acknowledgments

* [NaokiS] - for providing valuable information about the original DDR stage IO communication protocol.
* [Marco Ruggiero] - for designing the BlueDot logo and beta-testing the board on its own cabinet.
* [InteractiveHtmlBom] - the Kicad plugin used to generate the interactive BOM.
* [Kicad] - for allowing me to design this board for free!

<p align="right">(<a href="#readme-top">back to top</a>)</p>


[NaokiS]: http://nsaito.co.uk/
[Marco Ruggiero]: https://www.instagram.com/ruggiero.design/
[InteractiveHtmlBom]: https://github.com/openscopeproject/InteractiveHtmlBom
[Kicad]: https://www.kicad.org/
[LICENSE.txt]: /LICENSE.txt