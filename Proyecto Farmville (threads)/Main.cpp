#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <random>
#include <fstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
using namespace std;
//drawings 
// Constants for button dimensions
const int BUTTON_WIDTH = 100; 
const int BUTTON_HEIGHT = 30;
const int LABEL_OFFSET = 10;  // Offset for button label position
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 1000;
const int GRID_SIZE = 10;
const int BUTTON_SIZE = 50;
const int BUTTON_MARGIN = 10;
const int FONT_SIZE = 50;
const int TEXTBOX_WIDTH = 200;
const int TEXTBOX_HEIGHT = 30;
const int LABEL_WIDTH = 50;
const int LABEL_HEIGHT = 20;
const int LABEL_TEXT_OFFSET = 10; 
const int LABEL_TEXT_SIZE = FONT_SIZE;
const int NUM_INPUTS = 6;
const int INPUTBOX_X = 100;
const int INPUTBOX_Y = 100;
const int INPUTBOX_WIDTH = 200;
const int INPUTBOX_HEIGHT = 30;
const int LABEL_OFFSET_X = 10;
const int LABEL_OFFSET_Y = 5;
//Trees values
const int crecimiento_Binario = 200;
const int crecimiento_Heap = 150;
const int crecimiento_AVL = 500;
const int crecimiento_Splay = 500;
const int cantidad_Binario_AVL = 1;
const int cantidad_Heap_Splay = 2;
const int tiempo_Binario = 20;
const int tiempo_Heap = 35;
const int tiempo_AVL_Splay = 60;
int coins = 0;
int BTValue = 0;
int HeapValue = 0;
int AVLValue = 0;
int Tree4Value = 0;
int EspantapajarosValue = 0;

int fruitsGame = 0;
int fruitsBT = 0;
int fruitsHeap = 0;
int fruitsAVL = 0;
int fruitsSplay = 0;
bool fruitsBTFlag = false;
bool fruitsHeapFlag = false;
bool fruitsAVLFlag = false;
bool fruitsSplayFlag = false;
const float FIVE_MINUTES = 300.0;  // 5 minutes in seconds
const float ONE_MINUTE = 60.0;     // 1 minute in seconds
const float TWO_MINUTES = 120.0;   // 2 minutes in seconds
const float THREE_MINUTES = 180.0; // 3 minutes in seconds
const float FOUR_MINUTES = 240.0;  // 4 minutes in seconds
int espantapajos_quantity = 0;
int crow_spawn = 0;
int sheep_spawn = 0;
int crow_row = 0;
int crow_col = 0;
int sheep_row = 0;
int sheep_col = 0;
bool load = false;

//structs buttons handling
enum ButtonState {
    NORMAL,
    HOVER,
    CLICKED
};
struct Button {
    int x;
    int y;
    ButtonState state;
    ALLEGRO_BITMAP* backgroundImage; // Property to store the background image
    // Constructor
    Button() {
        backgroundImage = nullptr; // Initialize the backgroundImage to nullptr initially
    }
};
struct InputBox {
    string labelText;
    string text;
    int x;
    int y;
};
//new

//
void handleMouseClick(Button& button, int mouse_x, int mouse_y) {
    if (mouse_x >= button.x && mouse_x < button.x + BUTTON_SIZE &&
        mouse_y >= button.y && mouse_y < button.y + BUTTON_SIZE) {
        button.state = CLICKED;
    }
}
void handleMouseHover(Button& button, int mouse_x, int mouse_y) {
    if (mouse_x >= button.x && mouse_x < button.x + BUTTON_SIZE &&
        mouse_y >= button.y && mouse_y < button.y + BUTTON_SIZE) {
        button.state = HOVER;
    }
    else {
        button.state = NORMAL;
    }
}
void handleKeyboardInput(Button buttons[][GRID_SIZE], int& current_row, int& current_col, int key) {
    buttons[current_row][current_col].state = NORMAL;

    switch (key) {
    case ALLEGRO_KEY_UP:
        current_row = (current_row - 1 + GRID_SIZE) % GRID_SIZE;
        break;
    case ALLEGRO_KEY_DOWN:
        current_row = (current_row + 1) % GRID_SIZE;
        break;
    case ALLEGRO_KEY_LEFT:
        current_col = (current_col - 1 + GRID_SIZE) % GRID_SIZE;
        break;
    case ALLEGRO_KEY_RIGHT:
        current_col = (current_col + 1) % GRID_SIZE;
        break;
    }

    buttons[current_row][current_col].state = HOVER;
}
void incrementFruitsBT()
{
    while (true) {
        this_thread::sleep_for(chrono::seconds(20)); // Wait for 20 seconds
        fruitsGame++; // Increment fruitsGame by 1
        fruitsBT++;
    }
}
void incrementFruitsHeap()
{
    while (true) {
        this_thread::sleep_for(chrono::seconds(35)); 
        fruitsGame += 2; 
        fruitsHeap += 2;
    }
}
void incrementFruitsAVL()
{
    while (true) {
        this_thread::sleep_for(chrono::seconds(60)); 
        fruitsGame++; 
        fruitsAVL++;
    }
}
void incrementFruitsSplay()
{
    while (true) {
        this_thread::sleep_for(chrono::seconds(60));
        fruitsGame += 2;
        fruitsSplay += 2;
    }
} 
// Function to check if a point is inside a button
bool isPointInButton(int x, int y, int buttonX, int buttonY) {
    return (x >= buttonX && x <= buttonX + BUTTON_WIDTH && y >= buttonY && y <= buttonY + BUTTON_HEIGHT);
}
// Function to handle button click event
// Function to handle button click event
void HandleButtonClick(int x, int y) {
    if (x >= 400 - BUTTON_WIDTH && x <= 400 && y >= 0 && y <= BUTTON_HEIGHT) {
        load = true;
        cout << "loading data..." << endl;
    }
}
// Main function 
int main() {
    al_init();
    if (!al_init()) {
        cout << "Failed to initialize Allegro." << endl;
        return -1;
    }
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_keyboard();
    al_install_mouse();
    // Create config display
    ALLEGRO_DISPLAY* intro_display = al_create_display(400, 400);
    if (!intro_display) {
        std::cerr << "Failed to create intro display." << std::endl;
        return -1;
    }
    // Create the event queue for the intro display
    ALLEGRO_EVENT_QUEUE* intro_event_queue = al_create_event_queue();
    if (!intro_event_queue) {
        std::cerr << "Failed to create intro event queue." << std::endl;
        al_destroy_display(intro_display);
        return -1;
    }
    // Register events to the intro event queue
    al_register_event_source(intro_event_queue, al_get_display_event_source(intro_display));
    al_register_event_source(intro_event_queue, al_get_keyboard_event_source());
    al_register_event_source(intro_event_queue, al_get_mouse_event_source()); // new
    // Load the font for the intro display
    ALLEGRO_FONT* intro_font = al_create_builtin_font();
    if (!intro_font) {
        std::cerr << "Failed to create intro font." << std::endl;
        al_destroy_event_queue(intro_event_queue);
        al_destroy_display(intro_display);
        return -1;
    }
    // Create input boxes with customizable labels
    vector<InputBox> inputBoxes;
    vector<string> customLabels = { "Starting coins: ", "Binary tree value: ", "Heap tree value: ", "AVL tree value: ", "tree 4 value: ", "Espantapajaros value: " };
    int activeInputBoxIndex = 0; // Index of the currently active input box
    for (int i = 0; i < NUM_INPUTS; ++i) {
        InputBox inputBox;
        inputBox.x = INPUTBOX_X;
        inputBox.y = INPUTBOX_Y + i * (INPUTBOX_HEIGHT + BUTTON_MARGIN);
        inputBox.labelText = customLabels[i];
        inputBoxes.push_back(inputBox);
    }
    bool intro_display_open = true;
    // config display loop
    while (intro_display_open) {
        ALLEGRO_EVENT intro_event;
        al_wait_for_event_timed(intro_event_queue, &intro_event, 0.5); // Wait for events with a timeout of 0.5 seconds
        //input data events
        if (intro_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            if (intro_event.display.source == intro_display) {
                intro_display_open = false;
            }
        }
        else if (intro_event.type == ALLEGRO_EVENT_KEY_CHAR) {
            InputBox& activeInputBox = inputBoxes[activeInputBoxIndex]; // Get the currently active input box

            if (intro_event.keyboard.keycode == ALLEGRO_KEY_ENTER || intro_event.keyboard.keycode == ALLEGRO_KEY_PAD_ENTER) {
                // Handle Enter key press, you can perform some action here
                cout << activeInputBox.labelText << activeInputBox.text << endl;
                // Move to the next input box
                activeInputBoxIndex = (activeInputBoxIndex + 1) % NUM_INPUTS;
            }
            else if (intro_event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) {
                // Handle Backspace key press
                if (!activeInputBox.text.empty()) {
                    activeInputBox.text.pop_back();
                }
            }
            else if (isalnum(intro_event.keyboard.unichar) || intro_event.keyboard.unichar == ' ') {
                // Handle alphanumeric and space key presses
                activeInputBox.text += static_cast<char>(intro_event.keyboard.unichar);
            }
        }
        // Check for mouse button down event
        else if (intro_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            // Check if the button was clicked
            if (intro_event.mouse.button == 1) { // Left mouse button
                HandleButtonClick(intro_event.mouse.x, intro_event.mouse.y);
            }
        } 
        // Clear the intro display
        al_clear_to_color(al_map_rgb(220, 220, 220));
        // Draw the button
        al_draw_filled_rectangle(400 - BUTTON_WIDTH, 0, 400, BUTTON_HEIGHT, al_map_rgb(0, 0, 139));
        // Draw the label in the center of the button
        al_draw_text(intro_font, al_map_rgb(255, 255, 255), 400 - BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "Load");
        // Draw input boxes and labels
        for (const InputBox& inputBox : inputBoxes) {
            // Draw label
            al_draw_text(intro_font, al_map_rgb(0, 0, 0), inputBox.x, inputBox.y - LABEL_TEXT_OFFSET,
                ALLEGRO_ALIGN_LEFT, inputBox.labelText.c_str());

            // Draw input box
            al_draw_rectangle(inputBox.x + LABEL_WIDTH, inputBox.y, inputBox.x + LABEL_WIDTH + TEXTBOX_WIDTH, inputBox.y + TEXTBOX_HEIGHT,
                al_map_rgb(0, 0, 0), 2);
            al_draw_text(intro_font, al_map_rgb(0, 0, 0), inputBox.x + LABEL_WIDTH + 5, inputBox.y,
                ALLEGRO_ALIGN_LEFT, inputBox.text.c_str());
        }
        // Flip the intro display to update the screen
        al_flip_display();
    }
    // Clean up resources
    al_destroy_font(intro_font);
    al_destroy_display(intro_display);
    al_destroy_event_queue(intro_event_queue);
    // Access the user input from the input boxes
    if (load == false) {
        cout << "starting new game..." << endl;
        coins = stoi(inputBoxes[0].text);
        BTValue = stoi(inputBoxes[1].text);
        HeapValue = stoi(inputBoxes[2].text);
        AVLValue = stoi(inputBoxes[3].text);
        Tree4Value = stoi(inputBoxes[4].text);
        EspantapajarosValue = stoi(inputBoxes[5].text);
    }
    //intro display end
    //
    //
    //main display start
    // Create main display window
    ALLEGRO_DISPLAY* main_display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT); 
    if (!main_display) {
        cout << "Failed to create display." << endl;
        return -1;
    }
    // load font 
    ALLEGRO_FONT* font = al_load_font("C:/Windows/WinSxS/amd64_microsoft-windows-font-truetype-arial_31bf3856ad364e35_10.0.21996.1_none_f0538fe77f191da1/Arial.ttf", 24, 0);
    if (!font) {
        cout << "Failed to load font." << endl;
        return -1;
    }
    //main display background
    ALLEGRO_BITMAP* main_background = al_load_bitmap("C:/Users/HP/Pictures/AllegroBackground.png");
    if (!main_background) {
        cout << "Failed to load background image." << endl;
        al_destroy_font(font);
        al_destroy_display(main_display);
        return -1;
    }
    int image_width = al_get_bitmap_width(main_background);
    int image_height = al_get_bitmap_height(main_background);
    float scale_x = (float)WINDOW_WIDTH / image_width;
    float scale_y = (float)WINDOW_HEIGHT / image_height;
    //define button text
    const char* button_text = "";
    //calculate grid start position
    int grid_start_x = (WINDOW_WIDTH - (GRID_SIZE * (BUTTON_SIZE + BUTTON_MARGIN))) / 2;
    int grid_start_y = (WINDOW_HEIGHT - (GRID_SIZE * (BUTTON_SIZE + BUTTON_MARGIN))) / 2;
    //create buttons
    Button buttons[GRID_SIZE][GRID_SIZE];
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            int button_x = grid_start_x + col * (BUTTON_SIZE + BUTTON_MARGIN);
            int button_y = grid_start_y + row * (BUTTON_SIZE + BUTTON_MARGIN);

            buttons[row][col].x = button_x;
            buttons[row][col].y = button_y;
            buttons[row][col].state = NORMAL;
        }
    }
    int current_row = 0;
    int current_col = 0;
    //create main event queue
    ALLEGRO_EVENT_QUEUE* main_event_queue = al_create_event_queue();
    if (!main_event_queue) {
        cout << "Failed to create event queue." << endl;
        al_destroy_display(main_display);
        return -1;
    }
    // register event sources
    al_register_event_source(main_event_queue, al_get_keyboard_event_source());
    al_register_event_source(main_event_queue, al_get_mouse_event_source());
    al_register_event_source(main_event_queue, al_get_display_event_source(main_display));

    // Market button positions of main display
    int buttonWidthSum = BUTTON_WIDTH * 9;  // Total width of all buttons
    int market_buttonsX = (al_get_display_width(main_display) - buttonWidthSum) / 2;  // X-coordinate of the buttons block
    int market_button1X = market_buttonsX + BUTTON_WIDTH * 4;
    int market_button1Y = al_get_display_height(main_display) - BUTTON_HEIGHT - 10;
    int market_button2X = market_button1X + BUTTON_WIDTH;
    int market_button2Y = market_button1Y;
    int market_button3X = market_button2X + BUTTON_WIDTH;
    int market_button3Y = market_button1Y;
    int market_button4X = market_button3X + BUTTON_WIDTH;
    int market_button4Y = market_button1Y;
    int market_button5X = market_button4X + BUTTON_WIDTH;
    int market_button5Y = market_button1Y;
    int market_button6X = market_button1X - BUTTON_WIDTH;
    int market_button6Y = market_button1Y;
    int market_button7X = market_button6X - BUTTON_WIDTH;
    int market_button7Y = market_button1Y;
    int market_button8X = market_button7X - BUTTON_WIDTH;
    int market_button8Y = market_button1Y;
    int market_button9X = market_button8X - BUTTON_WIDTH;
    int market_button9Y = market_button1Y;
    // Market button labels
    string market_button1Label = "sell 1";
    string market_button2Label = "sell 2";
    string market_button3Label = "sell 5";
    string market_button4Label = "sell all";
    string market_button5Label = "Scarecrow";
    string market_BtButtonLabel = "Binary";
    string market_HeapButtonLabel = "Heap";
    string market_AVLButtonLabel = "AVL";
    string market_SplayButtonLabel = "Splay";
    // Define the buttons of plant display
    int button_size = 250;
    int button_margin = 20;
    int button_padding_x = (800 - (2 * button_size) - button_margin) / 2;
    int button_padding_y = (600 - (2 * button_size) - button_margin) / 2;
    //button1 characteristics
    int button1_x = button_padding_x;
    int button1_y = button_padding_y;
    //button2 characteristics
    int button2_x = button_padding_x + button_size + button_margin;
    int button2_y = button_padding_y;
    //button3 characteristics
    int button3_x = button_padding_x;
    int button3_y = button_padding_y + button_size + button_margin;
    //button4 characteristics
    int button4_x = button_padding_x + button_size + button_margin;
    int button4_y = button_padding_y + button_size + button_margin;
    //save button characteristics
    int save_buttonX = 10;
    int save_buttonY = al_get_display_height(main_display) / 2 - 150 / 2 - 100;
    int adjusted_save_buttonY = save_buttonY + 150 + 20;
    // 
    //buttons images
    ALLEGRO_BITMAP* button1_image = al_load_bitmap("C:/Users/HP/Pictures/BinaryTree2.png");
    ALLEGRO_BITMAP* button2_image = al_load_bitmap("C:/Users/HP/Pictures/HeapTree1.png");
    ALLEGRO_BITMAP* button3_image = al_load_bitmap("C:/Users/HP/Pictures/AVLTree.png");
    ALLEGRO_BITMAP* button4_image = al_load_bitmap("C:/Users/HP/Pictures/NoType1.png");
    ALLEGRO_BITMAP* farmer_image = al_load_bitmap("C:/Users/HP/Pictures/farmer.png");
    ALLEGRO_BITMAP* scarecrow_image = al_load_bitmap("C:/Users/HP/Pictures/scarecrow.png");
    ALLEGRO_BITMAP* crow_image = al_load_bitmap("C:/Users/HP/Pictures/crow.png");
    ALLEGRO_BITMAP* sheep_image = al_load_bitmap("C:/Users/HP/Pictures/sheep.png");
    //fruits timers
    vector<thread> timerThreadsBT; 
    vector<thread> timerThreadsHeap;
    vector<thread> timerThreadsAVL;
    vector<thread> timerThreadsSplay;
    //random generator
    random_device rd;  
    mt19937 gen(rd());
    uniform_int_distribution<> distribution1(1, 5);
    uniform_int_distribution<> distribution2(2, 20);
    uniform_int_distribution<> distribution3(5, 50);
    uniform_int_distribution<> crow_distribution(1, 1);
    uniform_int_distribution<> sheep_distribution(1, 1);
    uniform_int_distribution<> row_distribution(1, 10);
    uniform_int_distribution<> col_distribution(1, 10);
    // Create Allegro timer
    ALLEGRO_TIMER* timer = al_create_timer(1.0);  // 1 second interval
    // Register timer events
    al_register_event_source(main_event_queue, al_get_timer_event_source(timer));
    // Start the timer
    al_start_timer(timer);
    
    // load saved info
    if (load == true) {
        ifstream file("config.txt");
        if (!file.is_open()) {
            cout << "Failed to open config.txt.";
            return 1; // Return an error code
        }
        cout << "loading data..." << endl;
        string line;
        int lineCount = 0;

        // Read the file line by line
        while (std::getline(file, line)) {
            lineCount++;
            // Assign each line to respective variable
            switch (lineCount) {
            case 1:
                coins = stoi(line);
                break;
            case 2:
                BTValue = stoi(line);
                break;
            case 3:
                HeapValue = stoi(line);
                break;
            case 4:
                AVLValue = stoi(line);
                break;
            case 5:
                Tree4Value = stoi(line);
                break;
            case 6:
                EspantapajarosValue = stoi(line);
                break;
            case 7:
                fruitsBT = stoi(line);
                break;
            case 8:
                fruitsHeap = stoi(line);
                break;
            case 9:
                fruitsAVL = stoi(line);
                break;
            case 10:
                fruitsSplay = stoi(line);
                break;
            case 11:
                fruitsGame = stoi(line);
                break;
            case 12:
                espantapajos_quantity = stoi(line);
                break;
            default:
                break;
            }
            // Stop reading after 11 lines
            if (lineCount == 12) {
                cout << "Game loaded" << endl;
                break;
            }
        }
    }
    // flags
    bool timerFlag = true;
    bool minuteFlag = false;
    float elapsedSeconds = 0.0;
    bool open_plant_display = false;
    int coinsGame = coins;
    bool running = true;

    // main loop
    while (running) {
        ALLEGRO_EVENT event;
        al_wait_for_event(main_event_queue, &event);
        // Handle display close event
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            if (event.display.source == main_display) {
                running = false;
            }
        }
        else if (event.type == ALLEGRO_EVENT_TIMER) {
            elapsedSeconds += 1.0;

            // can generate 2 random number and use each one as row / col, to get the spawn position
            // mechanic is going to be to close plant a tree where the plague is 
            
            // every 2 minutes, make a 1/3 probability to spawn Sheep
            if (elapsedSeconds == TWO_MINUTES) {
                cout << "Sheep close to field!" << endl;
                sheep_spawn = sheep_distribution(gen);
                if (sheep_spawn == 1) {
                    sheep_row = row_distribution(gen);
                    sheep_col = col_distribution(gen);
                    buttons[sheep_row][sheep_col].backgroundImage = sheep_image;
                    cout << "Sheep spawned in: (" + to_string(sheep_row) + "," + to_string(sheep_col) + ")" << endl;
                }
                else {
                    cout << "Sheep went past the field" << endl;
                }
            }

            
            // if 3 minutes, make a 1/2 probability to spawn crow
            if (elapsedSeconds == THREE_MINUTES) {
                cout << "Crow close to field!" << endl;
                crow_spawn = crow_distribution(gen);
                if (crow_spawn == 1){
                    crow_row = row_distribution(gen);
                    crow_col = col_distribution(gen);
                    buttons[crow_row][crow_col].backgroundImage = crow_image;
                    cout << "Crow spawned in: (" + to_string(crow_row) + "," + to_string(crow_col) + ")" << endl;
                }
                else {
                    cout << "Crow went past the field" << endl;
                }
            }

            if (elapsedSeconds == FOUR_MINUTES) {
                cout << "Sheep close to field!" << endl;
                sheep_spawn = sheep_distribution(gen);
                if (sheep_spawn == 1) {
                    sheep_row = row_distribution(gen);
                    sheep_col = col_distribution(gen);
                    buttons[sheep_row][sheep_col].backgroundImage = sheep_image;
                    cout << "Sheep spawned in: (" + to_string(sheep_row) + "," + to_string(sheep_col) + ")" << endl;
                }
                else {
                    cout << "Sheep went past the field" << endl;
                }
            }

            
            // Five-minute timer
            if (elapsedSeconds <= FIVE_MINUTES) {
                timerFlag = true;
            }
            else {
                timerFlag = false;
                minuteFlag = true;
            }

            // Reset the timer
            if (elapsedSeconds >= FIVE_MINUTES + ONE_MINUTE) {
                elapsedSeconds = 0.0;
                minuteFlag = false;
            }
        } 
        else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            int mouse_x = event.mouse.x;
            int mouse_y = event.mouse.y;
            //sell 1
            if (minuteFlag == true) {
                if (isPointInButton(mouse_x, mouse_y, market_button1X, market_button1Y)) {
                    if (fruitsBTFlag == true) {
                        if (fruitsBT >= 1) {
                            coinsGame += distribution1(gen) * 1;
                            fruitsGame--;
                            fruitsBT--;
                            cout << "Sold 1 fruit!" << endl;
                        }
                        else {
                            al_show_native_message_box(NULL, "Error", "Not enough fruits to sell", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                        }
                    }
                    else if (fruitsHeapFlag == true) {
                        if (fruitsHeap >= 1) {
                            coinsGame += distribution1(gen) * 1;
                            fruitsHeap--;
                            fruitsGame--;
                            cout << "Sold 1 fruit!" << endl;
                        }
                        else {
                            al_show_native_message_box(NULL, "Error", "Not enough fruits to sell", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                        }
                    }
                    else if (fruitsAVLFlag == true) {
                        if (fruitsAVL >= 1) {
                            fruitsAVL--;
                            fruitsGame--;
                            coinsGame += distribution2(gen) * 1;
                            cout << "Sold 1 fruit!" << endl;
                        }
                        else {
                            al_show_native_message_box(NULL, "Error", "Not enough fruits to sell", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                        }
                    }
                    else if (fruitsSplayFlag == true) {
                        if (fruitsSplay >= 1) {
                            fruitsSplay--;
                            fruitsGame--;
                            coinsGame += distribution3(gen) * 1;
                            cout << "Sold 1 fruit!" << endl;
                        }
                        else {
                            al_show_native_message_box(NULL, "Error", "Not enough fruits to sell", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                        }
                    }
                    else {
                        al_show_native_message_box(NULL, "Error", "No tree type selected", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                    }
                }

                // sell 2
                else if (isPointInButton(mouse_x, mouse_y, market_button2X, market_button2Y)) {
                    if (fruitsBTFlag == true) {
                        if (fruitsBT >= 2) {
                            fruitsBT -= 2;
                            fruitsGame -= 2;
                            coinsGame += distribution1(gen) * 2;
                            cout << "Sold 2 fruits!" << endl;
                        }
                        else {
                            al_show_native_message_box(NULL, "Error", "Not enough fruits to sell", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                        }
                    }
                    else if (fruitsHeapFlag == true) {
                        if (fruitsHeap >= 2) {
                            fruitsHeap -= 2;
                            fruitsGame -= 2;
                            coinsGame += distribution1(gen) * 2;
                            cout << "Sold 2 fruits!" << endl;
                        }
                        else {
                            al_show_native_message_box(NULL, "Error", "Not enough fruits to sell", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                        }
                    }
                    else if (fruitsAVLFlag == true) {
                        if (fruitsAVL >= 2) {
                            fruitsAVL -= 2;
                            fruitsGame -= 2;
                            coinsGame += distribution2(gen) * 2;
                            cout << "Sold 2 fruits!" << endl;
                        }
                        else {
                            al_show_native_message_box(NULL, "Error", "Not enough fruits to sell", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                        }
                    }
                    else if (fruitsSplayFlag == true) {
                        if (fruitsSplay >= 2) {
                            fruitsSplay -= 2;
                            fruitsGame -= 2;
                            coinsGame += distribution3(gen) * 2;
                            cout << "Sold 2 fruits!" << endl;
                        }
                        else {
                            al_show_native_message_box(NULL, "Error", "Not enough fruits to sell", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                        }
                    }
                    else {
                        al_show_native_message_box(NULL, "Error", "No tree type selected", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                    }
                }

                //sell 5
                else if (isPointInButton(mouse_x, mouse_y, market_button3X, market_button3Y)) {
                    if (fruitsBTFlag == true) {
                        if (fruitsBT >= 5) {
                            fruitsBT -= 5;
                            fruitsGame -= 5;
                            coinsGame += distribution1(gen) * 5;
                            cout << "Sold 5 fruits!" << endl;
                        }
                        else {
                            al_show_native_message_box(NULL, "Error", "Not enough fruits to sell", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                        }
                    }
                    else if (fruitsHeapFlag == true) {
                        if (fruitsHeap >= 5) {
                            fruitsHeap -= 5;
                            fruitsGame -= 5;
                            coinsGame += distribution1(gen) * 5;
                            cout << "Sold 5 fruits!" << endl;
                        }
                        else {
                            al_show_native_message_box(NULL, "Error", "Not enough fruits to sell", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                        }
                    }
                    else if (fruitsAVLFlag == true) {
                        if (fruitsAVL >= 5) {
                            fruitsAVL -= 5;
                            fruitsGame -= 5;
                            coinsGame += distribution2(gen) * 5;
                            cout << "Sold 5 fruits!" << endl;
                        }
                        else {
                            al_show_native_message_box(NULL, "Error", "Not enough fruits to sell", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                        }
                    }
                    else if (fruitsSplayFlag == true) {
                        if (fruitsSplay >= 5) {
                            fruitsSplay -= 5;
                            fruitsGame -= 5;
                            coinsGame += distribution3(gen) * 5;
                            cout << "Sold 5 fruits!" << endl;
                        }
                        else {
                            al_show_native_message_box(NULL, "Error", "Not enough fruits to sell", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                        }
                    }
                    else {
                        al_show_native_message_box(NULL, "Error", "No tree type selected", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                    }
                }

                // sell all
                else if (isPointInButton(mouse_x, mouse_y, market_button4X, market_button4Y)) {
                    if (fruitsBTFlag == true) {
                        coinsGame += distribution1(gen) * fruitsBT;
                        fruitsGame -= fruitsBT;
                        fruitsBT = 0;
                        cout << "Sold all fruits!" << endl;
                    }
                    else if(fruitsHeapFlag == true){
                        coinsGame += distribution1(gen) * fruitsHeap;
                        fruitsGame -= fruitsHeap;
                        fruitsHeap = 0;
                        cout << "Sold all fruits!" << endl;
                    }
                    else if (fruitsAVLFlag == true){
                        coinsGame += distribution2(gen) * fruitsAVL;
                        fruitsGame -= fruitsAVL;
                        fruitsAVL = 0;
                        cout << "Sold all fruits!" << endl;
                    }
                    else if (fruitsSplayFlag == true) {
                        coinsGame += distribution3(gen) * fruitsSplay;
                        fruitsGame -= fruitsSplay;
                        fruitsSplay = 0;
                        cout << "Sold all fruits!" << endl;
                    }
                    else {
                        al_show_native_message_box(NULL, "Error", "No tree type selected", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                    }  
                }

                // buy espantapajaros
                else if (isPointInButton(event.mouse.x, event.mouse.y, market_button5X, market_button5Y)) {
                    if (espantapajos_quantity < 2 && (EspantapajarosValue) <= coinsGame) {
                        espantapajos_quantity++;
                        coinsGame -= (EspantapajarosValue);
                        cout << "Espantapajaros aquired!" << endl;
                    }
                    else {
                        al_show_native_message_box(NULL, "Error", "Limit surpassed or not enough coins to buy", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                    }
                }
            
                else if (isPointInButton(event.mouse.x, event.mouse.y, market_button6X, market_button6Y)) {
                    cout << "Binary tree selected!" << endl;
                    fruitsBTFlag = true;
                    fruitsHeapFlag = false;
                    fruitsAVLFlag = false;
                    fruitsSplayFlag = false;
                }
                else if (isPointInButton(event.mouse.x, event.mouse.y, market_button7X, market_button7Y)) {
                    cout << "Heap tree selected!" << endl;
                    fruitsBTFlag = false;
                    fruitsHeapFlag = true;
                    fruitsAVLFlag = false;
                    fruitsSplayFlag = false;
                }
                else if (isPointInButton(event.mouse.x, event.mouse.y, market_button8X, market_button8Y)) {
                    cout << "AVL tree selected!" << endl;
                    fruitsBTFlag = false;
                    fruitsHeapFlag = false;
                    fruitsAVLFlag = true;
                    fruitsSplayFlag = false;
                }
                else if (isPointInButton(event.mouse.x, event.mouse.y, market_button9X, market_button9Y)) {
                    cout << "Splay tree selected!" << endl;
                    fruitsBTFlag = false;
                    fruitsHeapFlag = false;
                    fruitsAVLFlag = false;
                    fruitsSplayFlag = true;
                }
                else if (event.mouse.button == 1) { // Left mouse button
                    for (int row = 0; row < GRID_SIZE; row++) {
                        for (int col = 0; col < GRID_SIZE; col++) {
                            handleMouseClick(buttons[row][col], mouse_x, mouse_y);
                        }
                    }
                }
            }
            else if (isPointInButton(event.mouse.x, event.mouse.y, save_buttonX, save_buttonY)) {
                ofstream file("config.txt", std::ios::trunc);
                if (!file.is_open()) {
                    cout << "Failed to open the file.";
                    return 1; // Return an error code
                }
                file << coinsGame << "\n";
                file << BTValue << "\n";
                file << HeapValue << "\n";
                file << AVLValue << "\n";
                file << Tree4Value << "\n";
                file << EspantapajarosValue << "\n";
                file << fruitsBT << "\n";
                file << fruitsHeap << "\n";
                file << fruitsAVL << "\n";
                file << fruitsSplay << "\n";
                file << fruitsGame << "\n";
                file << espantapajos_quantity << "\n";

                file.close();
                cout << "Game saved succesfully" << endl;;
            }
            else if (isPointInButton(event.mouse.x, event.mouse.y, save_buttonX, adjusted_save_buttonY)) {
                cout << "Scarecrow selected" << endl;
                if (espantapajos_quantity >= 1) {
                    buttons[current_row][current_col].backgroundImage = scarecrow_image;
                    espantapajos_quantity--;
                    cout << "Scarecrow planted!" << endl;
                }
                else {
                    al_show_native_message_box(NULL, "Error", "No scarecrows available", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                }
            }
        }
        else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
            int mouse_x = event.mouse.x;
            int mouse_y = event.mouse.y;

            for (int row = 0; row < GRID_SIZE; row++) {
                for (int col = 0; col < GRID_SIZE; col++) {
                    handleMouseHover(buttons[row][col], mouse_x, mouse_y);
                }
            }
        }
       
        else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            int key = event.keyboard.keycode;

            if (key == ALLEGRO_KEY_SPACE) {
                buttons[current_row][current_col].state = CLICKED;

                // Create a new display window
                ALLEGRO_DISPLAY* plant_display = al_create_display(800, 600);
                if (!plant_display) {
                    cout << "Failed to create new display." << endl;
                    return -1;
                }
                al_set_target_backbuffer(plant_display);
                al_set_target_backbuffer(main_display);
                al_set_target_bitmap(al_get_backbuffer(main_display));
                al_register_event_source(main_event_queue, al_get_display_event_source(main_display));
                ALLEGRO_BITMAP* plant_background = al_load_bitmap("C:/Users/HP/Pictures/plant_background.png");
                if (!plant_background) {
                    cout << "Failed to load background image." << endl;
                    al_destroy_display(plant_display);
                    return -1;
                }
                int image_width = al_get_bitmap_width(plant_background);
                int image_height = al_get_bitmap_height(plant_background);
                float scale_x = (float)800 / image_width;
                float scale_y = (float)600 / image_height;
               
                // while condition
                bool exit_clicked = false;
                while (!exit_clicked) {
                    ALLEGRO_EVENT button_event;
                    al_wait_for_event(main_event_queue, &button_event);

                    if (button_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                        if (button_event.mouse.button == 1) { // Left mouse button
                            int mouse_x = button_event.mouse.x;
                            int mouse_y = button_event.mouse.y;
                            // Check if any button was clicked
                            if (mouse_x >= button1_x && mouse_x <= button1_x + button_size &&
                                mouse_y >= button1_y && mouse_y <= button1_y + button_size) {
                                // Perform Button 1 functionality
                                
                                if (coinsGame >= BTValue) {
                                    coinsGame -= BTValue;
                                    exit_clicked = true; 
                                    buttons[current_row][current_col].backgroundImage = button1_image;
                                    cout << "Binary tree planted!" << endl;
                                    // Start a new timer thread
                                    timerThreadsBT.emplace_back(incrementFruitsBT);
                                }
                                else {
                                    al_show_native_message_box(NULL, "Error", "Not enough coins to buy the Tree", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                                    exit_clicked = true;
                                }
                            }
                            else if (mouse_x >= button2_x && mouse_x <= button2_x + button_size &&
                                mouse_y >= button2_y && mouse_y <= button2_y + button_size) {
                                // Perform Button 2 functionality
                                if (coinsGame >= HeapValue) {
                                    coinsGame -= HeapValue;
                                    buttons[current_row][current_col].backgroundImage = button2_image;
                                    cout << "Heap tree planted!" << endl;
                                    timerThreadsHeap.emplace_back(incrementFruitsHeap);
                                }
                                else {
                                    al_show_native_message_box(NULL, "Error", "Not enough coins to buy the Tree", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                                }
                                exit_clicked = true;
                            }
                            else if (mouse_x >= button3_x && mouse_x <= button3_x + button_size &&
                                mouse_y >= button3_y && mouse_y <= button3_y + button_size) {
                                // Perform Button 3 functionality
                                if (coinsGame >= AVLValue) {
                                    coinsGame -= AVLValue;
                                    buttons[current_row][current_col].backgroundImage = button3_image;
                                    cout << "AVL tree planted!" << endl;
                                    timerThreadsAVL.emplace_back(incrementFruitsAVL);
                                }
                                else {
                                    al_show_native_message_box(NULL, "Error", "Not enough coins to buy the Tree", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                                }
                                exit_clicked = true;
                            }
                            else if (mouse_x >= button4_x && mouse_x <= button4_x + button_size &&
                                mouse_y >= button4_y && mouse_y <= button4_y + button_size) {
                                // Perform Button 4 functionality
                                if (coinsGame >= Tree4Value) {
                                    coinsGame -= Tree4Value;
                                    buttons[current_row][current_col].backgroundImage = button4_image;
                                    cout << "Splay tree planted!" << endl;
                                    timerThreadsSplay.emplace_back(incrementFruitsSplay);
                                }
                                else {
                                    al_show_native_message_box(NULL, "Error", "Not enough coins to buy the Tree", "Failed", NULL, ALLEGRO_MESSAGEBOX_ERROR);
                                }
                                exit_clicked = true;
                            }
                        }
                    }
                    else if (button_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                        if (button_event.display.source == plant_display) {
                            exit_clicked = true;
                        }
                    }
                    else if (button_event.type == ALLEGRO_EVENT_KEY_DOWN) {
                        // Check if a specific key was pressed to close the plant_display
                        if (button_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                            exit_clicked = true;
                        }
                    }
                    // Clear the plant_display to black
                    al_set_target_backbuffer(plant_display);
                    // Clear the plant_display to black
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    // Draw background image
                    al_draw_scaled_bitmap(plant_background, 0, 0, image_width, image_height, 0, 0, 800, 600, 0);
                    // Draw background images for each button
                    al_draw_scaled_bitmap(button1_image, 0, 0, al_get_bitmap_width(button1_image), al_get_bitmap_height(button1_image), button1_x, button1_y, button_size, button_size, 0);
                    al_draw_scaled_bitmap(button2_image, 0, 0, al_get_bitmap_width(button2_image), al_get_bitmap_height(button2_image), button2_x, button2_y, button_size, button_size, 0);
                    al_draw_scaled_bitmap(button3_image, 0, 0, al_get_bitmap_width(button3_image), al_get_bitmap_height(button3_image), button3_x, button3_y, button_size, button_size, 0);
                    al_draw_scaled_bitmap(button4_image, 0, 0, al_get_bitmap_width(button4_image), al_get_bitmap_height(button4_image), button4_x, button4_y, button_size, button_size, 0);
                    // Draw labels for each button
                    int label_y_offset = 10; // Adjust this value to control the vertical position of the labels
                    al_draw_text(font, al_map_rgb(0, 0, 0), button1_x + button_size / 2, button1_y + button_size - al_get_font_ascent(font) - label_y_offset, ALLEGRO_ALIGN_CENTER, "Binary tree");
                    al_draw_text(font, al_map_rgb(0, 0, 0), button2_x + button_size / 2, button2_y + button_size - al_get_font_ascent(font) - label_y_offset, ALLEGRO_ALIGN_CENTER, "Heap tree");
                    al_draw_text(font, al_map_rgb(0, 0, 0), button3_x + button_size / 2, button3_y + button_size - al_get_font_ascent(font) - label_y_offset, ALLEGRO_ALIGN_CENTER, "AVL tree");
                    al_draw_text(font, al_map_rgb(0, 0, 0), button4_x + button_size / 2, button4_y + button_size - al_get_font_ascent(font) - label_y_offset, ALLEGRO_ALIGN_CENTER, "Splay tree");
                    // Flip the plant_display to update the screen
                    al_flip_display();
                    // Restoring the target backbuffer to main_display
                    al_set_target_backbuffer(main_display);
                    // Flip the main_display to update the screen
                    al_flip_display();
                    // Check if the exit flag is set
                    if (exit_clicked) {
                        al_destroy_display(plant_display); // Destroy the plant_display object
                    }
                }
            }
            else if (key == ALLEGRO_KEY_UP || key == ALLEGRO_KEY_DOWN ||
                key == ALLEGRO_KEY_LEFT || key == ALLEGRO_KEY_RIGHT) {
                handleKeyboardInput(buttons, current_row, current_col, key);
            }
        }
        al_draw_scaled_bitmap(main_background, 0, 0, image_width, image_height, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

        //new
        // Define a flag to track the modified state of each button
        bool modifiedButtons[GRID_SIZE][GRID_SIZE] = { false };
        //

        for (int row = 0; row < GRID_SIZE; row++) {
            for (int col = 0; col < GRID_SIZE; col++) {
                Button& button = buttons[row][col];

                
                if (button.backgroundImage != button1_image &&
                    button.backgroundImage != button2_image &&
                    button.backgroundImage != button3_image &&
                    button.backgroundImage != button4_image &&
                    button.backgroundImage != scarecrow_image &&
                    button.backgroundImage != sheep_image) {
                    al_draw_filled_rectangle(button.x, button.y, button.x + BUTTON_SIZE, button.y + BUTTON_SIZE, al_map_rgb(0, 0, 0));
                }
                
                switch (button.state) {
                case NORMAL:
                    al_draw_filled_rectangle(button.x, button.y, button.x + BUTTON_SIZE, button.y + BUTTON_SIZE, al_map_rgb(0, 128, 0));
                    al_draw_text(font, al_map_rgb(255, 255, 255), button.x + BUTTON_SIZE / 2, button.y + BUTTON_SIZE / 2 - al_get_font_ascent(font) / 2, ALLEGRO_ALIGN_CENTER, button_text);
                    break;
                case HOVER:
                    al_draw_filled_rectangle(button.x, button.y, button.x + BUTTON_SIZE, button.y + BUTTON_SIZE, al_map_rgb(128, 128, 0));
                    al_draw_text(font, al_map_rgb(255, 255, 255), button.x + BUTTON_SIZE / 2, button.y + BUTTON_SIZE / 2 - al_get_font_ascent(font) / 2, ALLEGRO_ALIGN_CENTER, button_text);
                    //new
                    // Check if current button has a crow_image background
                    if (button.backgroundImage == crow_image || button.backgroundImage == sheep_image) {
                        buttons[row][col].backgroundImage = nullptr;
                        modifiedButtons[row][col] = true; // Set the modified flag
                        cout << "Plague has been removed by Farmer!" << endl;
                        cout << "1 fruit eaten" << endl;
                    }
                    //
                    break;
                case CLICKED:
                    al_draw_filled_rectangle(button.x, button.y, button.x + BUTTON_SIZE, button.y + BUTTON_SIZE, al_map_rgb(128, 0, 0));
                    al_draw_text(font, al_map_rgb(255, 255, 255), button.x + BUTTON_SIZE / 2, button.y + BUTTON_SIZE / 2 - al_get_font_ascent(font) / 2, ALLEGRO_ALIGN_CENTER, button_text);
                    break;
                }

                if (button.backgroundImage == button1_image ||
                    button.backgroundImage == button2_image ||
                    button.backgroundImage == button3_image ||
                    button.backgroundImage == button4_image ||
                    button.backgroundImage == scarecrow_image ||
                    button.backgroundImage == crow_image ||
                    button.backgroundImage == sheep_image) {
                    al_draw_scaled_bitmap(button.backgroundImage, 0, 0, al_get_bitmap_width(button.backgroundImage), al_get_bitmap_height(button.backgroundImage),
                        button.x, button.y, BUTTON_SIZE, BUTTON_SIZE, 0);
                }

                // Draw farmer image if available
                if (row == current_row && col == current_col) {
                    if (button.backgroundImage != nullptr && 
                        button.backgroundImage != button1_image &&
                        button.backgroundImage != button2_image &&
                        button.backgroundImage != button3_image &&
                        button.backgroundImage != button4_image &&
                        button.backgroundImage != scarecrow_image &&
                        button.backgroundImage != crow_image &&
                        button.backgroundImage != sheep_image) {
                        al_draw_scaled_bitmap(button.backgroundImage, 0, 0, al_get_bitmap_width(button.backgroundImage), al_get_bitmap_height(button.backgroundImage),
                            button.x, button.y, BUTTON_SIZE, BUTTON_SIZE, 0);
                    }
                    else {
                        al_draw_scaled_bitmap(farmer_image, 0, 0, al_get_bitmap_width(farmer_image), al_get_bitmap_height(farmer_image),
                            button.x, button.y, BUTTON_SIZE, BUTTON_SIZE, 0);
                    }
                }
            }
        }
        // Draw market buttons
        al_draw_filled_rectangle(market_button1X, market_button1Y, market_button1X + BUTTON_WIDTH, market_button1Y + BUTTON_HEIGHT, al_map_rgb(176, 224, 230));
        al_draw_filled_rectangle(market_button2X, market_button2Y, market_button2X + BUTTON_WIDTH, market_button2Y + BUTTON_HEIGHT, al_map_rgb(273, 216, 220));
        al_draw_filled_rectangle(market_button3X, market_button3Y, market_button3X + BUTTON_WIDTH, market_button3Y + BUTTON_HEIGHT, al_map_rgb(135, 206, 250));
        al_draw_filled_rectangle(market_button4X, market_button4Y, market_button4X + BUTTON_WIDTH, market_button4Y + BUTTON_HEIGHT, al_map_rgb(100, 149, 237));
        al_draw_filled_rectangle(market_button5X, market_button5Y, market_button5X + BUTTON_WIDTH, market_button5Y + BUTTON_HEIGHT, al_map_rgb(65, 105, 225));
        al_draw_filled_rectangle(market_button6X, market_button6Y, market_button6X + BUTTON_WIDTH, market_button6Y + BUTTON_HEIGHT, al_map_rgb(255, 0, 0));
        al_draw_filled_rectangle(market_button7X, market_button7Y, market_button7X + BUTTON_WIDTH, market_button7Y + BUTTON_HEIGHT, al_map_rgb(250, 128, 114));
        al_draw_filled_rectangle(market_button8X, market_button8Y, market_button8X + BUTTON_WIDTH, market_button8Y + BUTTON_HEIGHT, al_map_rgb(240, 128, 128));
        al_draw_filled_rectangle(market_button9X, market_button9Y, market_button9X + BUTTON_WIDTH, market_button9Y + BUTTON_HEIGHT, al_map_rgb(220, 20, 60));

        // Draw market button labels
        al_draw_text(font, al_map_rgb(255, 255, 255), market_button1X + BUTTON_WIDTH / 2, market_button1Y + BUTTON_HEIGHT / 2 - LABEL_OFFSET, ALLEGRO_ALIGN_CENTER, market_button1Label.c_str());
        al_draw_text(font, al_map_rgb(255, 255, 255), market_button2X + BUTTON_WIDTH / 2, market_button2Y + BUTTON_HEIGHT / 2 - LABEL_OFFSET, ALLEGRO_ALIGN_CENTER, market_button2Label.c_str());
        al_draw_text(font, al_map_rgb(255, 255, 255), market_button3X + BUTTON_WIDTH / 2, market_button3Y + BUTTON_HEIGHT / 2 - LABEL_OFFSET, ALLEGRO_ALIGN_CENTER, market_button3Label.c_str());
        al_draw_text(font, al_map_rgb(255, 255, 255), market_button4X + BUTTON_WIDTH / 2, market_button4Y + BUTTON_HEIGHT / 2 - LABEL_OFFSET, ALLEGRO_ALIGN_CENTER, market_button4Label.c_str());
        al_draw_text(font, al_map_rgb(255, 255, 255), market_button5X + BUTTON_WIDTH / 2, market_button5Y + BUTTON_HEIGHT / 2 - LABEL_OFFSET, ALLEGRO_ALIGN_CENTER, market_button5Label.c_str());
        al_draw_text(font, al_map_rgb(255, 255, 255), market_button6X + BUTTON_WIDTH / 2, market_button6Y + BUTTON_HEIGHT / 2 - LABEL_OFFSET, ALLEGRO_ALIGN_CENTER, market_BtButtonLabel.c_str());
        al_draw_text(font, al_map_rgb(255, 255, 255), market_button7X + BUTTON_WIDTH / 2, market_button7Y + BUTTON_HEIGHT / 2 - LABEL_OFFSET, ALLEGRO_ALIGN_CENTER, market_HeapButtonLabel.c_str());
        al_draw_text(font, al_map_rgb(255, 255, 255), market_button8X + BUTTON_WIDTH / 2, market_button8Y + BUTTON_HEIGHT / 2 - LABEL_OFFSET, ALLEGRO_ALIGN_CENTER, market_AVLButtonLabel.c_str());
        al_draw_text(font, al_map_rgb(255, 255, 255), market_button9X + BUTTON_WIDTH / 2, market_button9Y + BUTTON_HEIGHT / 2 - LABEL_OFFSET, ALLEGRO_ALIGN_CENTER, market_SplayButtonLabel.c_str());

        // Draw fruits label
        string fruitsLabel = "All fruits: " + to_string(fruitsGame);
        string btTreeFruitLabel = "Binary fruits: " + to_string(fruitsBT);
        string heapTreeFruitLabel = "Heap fruits: " + to_string(fruitsHeap);
        string AVLTreeFruitLabel = "AVL fruits: " + to_string(fruitsAVL);
        string splayTreeFruitLabel = "Splay fruits: " + to_string(fruitsSplay);
        string coinsLabel = "Coins: " + to_string(coinsGame);
        string espantapajarosLabel = "Scarecrow available: " + to_string(espantapajos_quantity);
        string saveLabel = "Save";
        
        int fruitsLabelX = market_button5X - al_get_text_width(font, fruitsLabel.c_str()) - 10;
        int fruitsLabelY = market_button5Y + BUTTON_HEIGHT / 2 - al_get_font_ascent(font) / 2;  // Adjusted for text alignment
        al_draw_text(font, al_map_rgb(0, 0, 139), fruitsLabelX, fruitsLabelY - 30, 0, fruitsLabel.c_str());
        al_draw_text(font, al_map_rgb(220, 20, 60), fruitsLabelX, fruitsLabelY - 60, 0, btTreeFruitLabel.c_str());
        al_draw_text(font, al_map_rgb(220, 20, 60), fruitsLabelX, fruitsLabelY - 90, 0, heapTreeFruitLabel.c_str());
        al_draw_text(font, al_map_rgb(220, 20, 60), fruitsLabelX, fruitsLabelY - 120, 0, AVLTreeFruitLabel.c_str());
        al_draw_text(font, al_map_rgb(220, 20, 60), fruitsLabelX, fruitsLabelY - 150, 0, splayTreeFruitLabel.c_str());
        al_draw_text(font, al_map_rgb(0, 0, 139), WINDOW_WIDTH - 10, 10, ALLEGRO_ALIGN_RIGHT, coinsLabel.c_str());

        // espantapajaros label
        int labelX = 10;
        int labelY = WINDOW_HEIGHT - 90; 
        int labelWidth = WINDOW_WIDTH;
        int labelHeight = 90;
        al_draw_text(font, al_map_rgb(0, 0, 139), labelX, labelY, ALLEGRO_ALIGN_LEFT, espantapajarosLabel.c_str());

        // Draw save button
        al_draw_filled_rectangle(save_buttonX, save_buttonY, save_buttonX + BUTTON_WIDTH, save_buttonY + BUTTON_HEIGHT, al_map_rgb(0, 0, 139));
        al_draw_text(font, al_map_rgb(255, 255, 255), save_buttonX + BUTTON_WIDTH / 2, save_buttonY + BUTTON_HEIGHT / 2 - LABEL_OFFSET, ALLEGRO_ALIGN_CENTER, saveLabel.c_str());
        // Draw scarecrow button
        int imageWidth = al_get_bitmap_width(scarecrow_image);
        int imageHeight = al_get_bitmap_height(scarecrow_image);
        al_draw_scaled_bitmap(scarecrow_image, 0, 0, imageWidth, imageHeight, save_buttonX, save_buttonY + 150 + 20, 150, 150, 0);
        
        // Render the countdown labels
        if (timerFlag) {
            string countdownLabel = "Market opens in: " + to_string((int)(FIVE_MINUTES - elapsedSeconds)) + " seconds";
            al_draw_text(font, al_map_rgb(128, 0, 0), 10, 10, 0, countdownLabel.c_str());
        }
        else if (minuteFlag) {
            string countdownLabel = "Market time left: " + to_string((int)(ONE_MINUTE - (elapsedSeconds - FIVE_MINUTES))) + " seconds";
            al_draw_text(font, al_map_rgb(220, 20, 60), 10, 40, 0, countdownLabel.c_str());
        }
        al_flip_display();
    }
    // Wait for all timer threads to finish
    for (auto& thread : timerThreadsBT) {
        thread.join();
    }
    for (auto& thread : timerThreadsHeap) {
        thread.join();
    }
    for (auto& thread : timerThreadsAVL) {
        thread.join();
    }
    for (auto& thread : timerThreadsSplay) {
        thread.join();
    }
    
    al_destroy_bitmap(button1_image);
    al_destroy_bitmap(button2_image);
    al_destroy_bitmap(button3_image);
    al_destroy_bitmap(button4_image);
    al_destroy_bitmap(scarecrow_image);
    al_uninstall_mouse(); 
    al_uninstall_keyboard();
    al_destroy_bitmap(main_background);
    al_destroy_font(font);
    al_destroy_display(main_display);
    al_destroy_event_queue(main_event_queue);
    al_destroy_timer(timer);
 
    return 0;
}
