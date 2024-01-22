#pragma once    
#include <SFML/Graphics.hpp>
#include <iostream>

class PopupMenu {
public:
    PopupMenu(sf::RenderWindow& window) : window_(window), rolledUp_(false) {
        // Load font (you can replace this with your own font)
        if (!font_.loadFromFile("assets/ModernAntiqua-Zw5K.ttf")) {
            std::cerr << "Error loading font." << std::endl;
        }

        // Initialize menu items
        createMenuItem("Option 1", "icon1.png");
        createMenuItem("Option 2", "icon2.png");

        // Set initial state
        updateMenuVisibility();
    }

    void toggleRoll() {
        rolledUp_ = !rolledUp_;
        updateMenuVisibility();
    }

    void display() {
        while (window_.isOpen()) {
            sf::Event event;
            while (window_.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window_.close();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                    toggleRoll(); // Toggle roll/unroll on Space key press
                }
            }

            // Draw menu items
            if (!rolledUp_) {
                for (const auto& item : menuItems_) {
                    window_.draw(item.text);
                    window_.draw(item.icon);
                }
            }
            else {
                window_.draw(menuTitle_);
            }

            window_.display();
        }
    }

private:
    struct MenuItem {
        sf::Text text;
        sf::Sprite icon;
    };

    void createMenuItem(const std::string& label, const std::string& iconFilename) {
        MenuItem item;

        // Set up text
        item.text.setFont(font_);
        item.text.setString(label);
        item.text.setCharacterSize(24);
        item.text.setFillColor(sf::Color::White);
        item.text.setPosition(50, 100 * menuItems_.size());

        // Set up icon
        if (itemTexture_.loadFromFile(iconFilename)) {
            item.icon.setTexture(itemTexture_);
            item.icon.setPosition(20, 100 * menuItems_.size() + 10);
        }
        else {
            std::cerr << "Error loading icon: " << iconFilename << std::endl;
        }

        menuItems_.push_back(item);
    }

    void updateMenuVisibility() {
        if (!rolledUp_) {
            menuTitle_.setFont(font_);
            menuTitle_.setString("Menu (Press Space to Roll Up)");
            menuTitle_.setCharacterSize(24);
            menuTitle_.setFillColor(sf::Color::White);
            menuTitle_.setPosition(50, 0);
        }
    }

    sf::RenderWindow& window_;
    sf::Font font_;
    sf::Texture itemTexture_;
    std::vector<MenuItem> menuItems_;
    sf::Text menuTitle_;
    bool rolledUp_;
};

//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Rollable Popup Menu Example");
//    PopupMenu popupMenu(window);
//    popupMenu.display();
//
//    return 0;
//}
