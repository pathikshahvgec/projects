# TVN Game Show

A simple interactive game show application that tracks correct and incorrect answers and plays corresponding sound effects.

## Features

- Interactive graphical user interface (GUI) for tracking correct and wrong answers.
- Command-line interface (CLI) for tracking quiz responses.
- Plays sounds for correct and incorrect answers using the `pygame.mixer` module.

## Requirements

- Python 3.x
- `pygame` library for sound playback
- `tkinter` for GUI

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/tvn-game-show.git
   cd tvn-game-show
   ```

2. Install the required dependencies:
   ```bash
   pip install pygame
   ```

3. Make sure the sound files are placed in the `hfprog_sounds` directory:
   - `correct.wav`: For correct answers
   - `wrong.wav`: For incorrect answers

## Usage

### GUI Version

Run the GUI application:
```bash
python tvn_gui.py
```

- Click **Correct!** to increment the correct answer count.
- Click **Wrong!** to increment the wrong answer count.
- Both buttons play corresponding sounds.

### CLI Version

Run the CLI application:
```bash
python tvn_cli.py
```

- Input `1` for correct, `2` for wrong, and `0` to quit.
- A summary of responses is displayed when you exit the application.

## File Structure

- `tvn_gui.py`: The GUI application.
- `tvn_cli.py`: The command-line version of the game.
- `playSound.py`: A helper module for playing sound files using `pygame.mixer`.

## Dependencies

- `pygame`: Handles sound playback.
- `tkinter`: Creates the graphical user interface.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

Special thanks to:
- The `pygame` team for providing the sound library.
- The Python community for their continuous support.

---

Feel free to modify and improve this application!
```

Let me know if you'd like to customize or add specific sections!
