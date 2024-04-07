
/**
 * @file TimedButton.hpp
 * @author Alexandre Rancati-Palmer (a.rancatipalmer@mailo.com)
 * @brief Class providing a button with:
 * - Flexible Debouncing
 * - Press duration in milliseconds
 * OBS: Note that pressing the button is a blocking action for the processor.
 * @version 0.1
 * @date 2024-04-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once
#include <Arduino.h>
#include <stdint.h>

class TimedButton {
 public:
  /**
   * @brief Construct a new Timed Button object
   *
   * @param button_pin Pin to which the physical button is connected
   * @param interval Interval in Millisecond after which the button is
   * considered pressed
   * @param pressed_state The expected reading from the pin when the button is
   * pressed (True if HIGH and False if LOW)
   */
  TimedButton(uint8_t button_pin, uint16_t interval, bool pressed_state);

  /**
   * @brief Destroy the Timed Button object
   *
   */
  ~TimedButton();

  /**
   * @brief Initialise the button.
   * Needs to be called before usage.
   */
  void init();

  /**
   * @brief Return the status of the button based on the provided interval.
   * OBS: Pressing the button is a blocking action.
   *
   * @return true If the button has been pressed at least for the duration of
   * the interval.
   * @return false If the button has not beed pressed long enough.
   */
  bool isPressed();

  /**
   * @brief Get the duration for which the button is being pressed.
   * OBS: Pressing the button is a blocking action.
   *
   * @return long
   */
  uint64_t getPressedTime();

  /**
   * @brief Set the interval allowing to change the behaviour of the button
   * dynamically
   *
   * @param new_interval
   */
  void setInterval(uint16_t new_interval);

 private:
  uint8_t m_button_pin;
  uint16_t m_interval;
  bool m_pressed_state;
  uint64_t m_current_time;
  uint64_t m_start_time;
};
