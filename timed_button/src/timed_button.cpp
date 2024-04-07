/**
 * @file timed_button.cpp
 * @author Alexandre Rancati-Palmer (a.rancatipalmer@mailo.com)
 * @brief Implementation of timed_button/timed_button.hpp
 * @version 0.1
 * @date 2024-04-07
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "timed_button.hpp"

TimedButton::TimedButton(uint8_t button_pin, uint16_t interval,
                         bool pressed_state) {
  m_button_pin = button_pin;
  m_interval = interval;
  m_pressed_state = pressed_state;
}

TimedButton::~TimedButton() {}

void TimedButton::init() { pinMode(m_button_pin, INPUT); }

uint64_t TimedButton::getPressedTime() {
  m_start_time = millis();
  m_current_time = 0;
  while (digitalRead(m_button_pin) == m_pressed_state) {
    m_current_time = millis();
  }
  
  uint64_t result = (m_current_time == 0) ? 0 : (m_current_time - m_start_time);
  return result;
}

void TimedButton::setInterval(uint16_t new_interval) {
  m_interval = new_interval;
}

bool TimedButton::isPressed() { return (getPressedTime() >= m_interval); }
