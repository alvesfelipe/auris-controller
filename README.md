# MUSIC FOR DEAF

This project promotes a translation of a .wav file to a new format (Auris Stream) to be interpreted by a haptics interface, in order to promote a better music experience for deaf users.

The project use the [audio_to_midi_melodia] script for extract the melody notes from an audio file and export them to MIDI.

### Version
1.1

### Dependencies
	
MUSIC FOR DEAF uses a number of depenencies to work propetly:

* [audio_to_midi_melodia] - Dependencies:
	* [Melodia melody extraction Vamp plugin]
	* [Librosa]
	* [Vamp python module]
	* [midiutil]
	* [NumPy & SciPy]
	* [JAMS]

* [Boost.Filesystem library]
```sh
$ sudo apt-get install libboost-filesystem-dev
```
If you whant to play Auris midi in a haptics interface, you will need:
* [wiringpi]

### Complie and run Music For Deaf

For compile and run Music For Deaf code run:

```sh
$ cd $(HOME)/MUSIC_DEAF/music_for_deaf/auris-controller
```
```sh
$ make
```
```sh
$ make run
```

### Contributors
* Felipe Alves Araújo felipealves@lavid.ufpb.br

[audio_to_midi_melodia]: <https://github.com/justinsalamon/audio_to_midi_melodia>
[Melodia melody extraction Vamp plugin]: <http://mtg.upf.edu/technologies/melodia>
[Librosa]: <https://github.com/librosa/librosa>
[Vamp python module]: <https://pypi.python.org/pypi/vamp>
[midiutil]: <https://code.google.com/p/midiutil/>
[NumPy & SciPy]: <http://www.scipy.org/>
[JAMS]: <https://github.com/marl/jams>
[Boost.Filesystem library]: <http://www.boost.org/doc/libs/1_37_0/libs/filesystem/doc/index.htm>
[wiringpi]: <http://wiringpi.com/download-and-install/>