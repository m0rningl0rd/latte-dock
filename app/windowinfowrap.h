/*
*  Copyright 2016  Smith AR <audoban@openmailbox.org>
*                  Michail Vourlakos <mvourlakos@gmail.com>
*
*  This file is part of Latte-Dock
*
*  Latte-Dock is free software; you can redistribute it and/or
*  modify it under the terms of the GNU General Public License as
*  published by the Free Software Foundation; either version 2 of
*  the License, or (at your option) any later version.
*
*  Latte-Dock is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef WINDOWINFOWRAP_H
#define WINDOWINFOWRAP_H

#include <QWindow>
#include <QRect>

namespace Latte {

class WindowInfoWrap {
    Q_DISABLE_COPY(WindowInfoWrap)

public:
    constexpr WindowInfoWrap() noexcept
        : m_isValid(false)
        , m_isActive(false)
        , m_isMinimized(false)
        , m_isMaxVert(false)
        , m_isMaxHorz(false)
        , m_isFullscreen(false)
        , m_isShaded(false)
        , m_isPlasmaDesktop(false)
    {
    }

     constexpr WindowInfoWrap(WindowInfoWrap &&o) noexcept
        : m_wid(std::move(o.m_wid))
        , m_geometry(std::move(o.m_geometry))
        , m_isValid(o.m_isValid)
        , m_isActive(o.m_isActive)
        , m_isMinimized(o.m_isMinimized)
        , m_isMaxVert(o.m_isMaxVert)
        , m_isMaxHorz(o.m_isMaxHorz)
        , m_isFullscreen(o.m_isFullscreen)
        , m_isShaded(o.m_isShaded)
        , m_isPlasmaDesktop(o.m_isPlasmaDesktop)
    {
    }

    inline WindowInfoWrap &operator=(WindowInfoWrap &&rhs) noexcept;
    constexpr bool operator==(const WindowInfoWrap &rhs) const noexcept;
    constexpr bool operator<(const WindowInfoWrap &rhs) const noexcept;
    constexpr bool operator>(const WindowInfoWrap &rhs) const noexcept;

    constexpr bool isValid() const noexcept;
    inline void setIsValid(bool isValid) noexcept;

    constexpr bool isActive() const noexcept;
    inline void setIsActive(bool isActive) noexcept;

    constexpr bool isMinimized() const noexcept;
    inline void setIsMinimized(bool isMinimized) noexcept;

    constexpr bool isMaximized() const noexcept;

    constexpr bool isMaxVert() const noexcept;
    inline void setIsMaxVert(bool isMaxVert) noexcept;

    constexpr bool isMaxHoriz() const noexcept;
    inline void setIsMaxHoriz(bool isMaxHoriz) noexcept;

    constexpr bool isFullscreen() const noexcept;
    inline void setIsFullscreen(bool isFullscreen) noexcept;

    constexpr bool isShaded() const noexcept;
    inline void setIsShaded(bool isShaded) noexcept;

    constexpr bool isPlasmaDesktop() const noexcept;
    inline void setIsPlasmaDesktop(bool isPlasmaDesktop) noexcept;

    constexpr QRect geometry() const noexcept;
    inline void setGeometry(const QRect &geometry) noexcept;

    constexpr WId wid() const noexcept;
    inline void setWid(WId wid) noexcept;

private:
    WId m_wid {0};
    QRect m_geometry;

    bool m_isValid : 1;
    bool m_isActive : 1;
    bool m_isMinimized : 1;
    bool m_isMaxVert : 1;
    bool m_isMaxHorz : 1;
    bool m_isFullscreen : 1;
    bool m_isShaded : 1;
    bool m_isPlasmaDesktop : 1;
};

// BEGIN: definitions
inline WindowInfoWrap &WindowInfoWrap::operator=(WindowInfoWrap &&rhs) noexcept
{
    m_wid = std::move(rhs.m_wid);
    m_geometry = std::move(rhs.m_geometry);
    m_isValid = rhs.m_isValid;
    m_isActive = rhs.m_isActive;
    m_isMinimized = rhs.m_isMinimized;
    m_isMaxVert = rhs.m_isMaxVert;
    m_isMaxHorz = rhs.m_isMaxHorz;
    m_isFullscreen = rhs.m_isFullscreen;
    m_isShaded = rhs.m_isShaded;
    m_isPlasmaDesktop = rhs.m_isPlasmaDesktop;
    return *this;
}

constexpr bool WindowInfoWrap::operator==(const WindowInfoWrap &rhs) const noexcept
{
    return m_wid == rhs.m_wid;
}

constexpr bool WindowInfoWrap::operator<(const WindowInfoWrap &rhs) const noexcept
{
    return m_wid < rhs.m_wid;
}

constexpr bool WindowInfoWrap::operator>(const WindowInfoWrap &rhs) const noexcept
{
    return m_wid > rhs.m_wid;
}

constexpr bool WindowInfoWrap::isValid() const noexcept
{
    return m_isValid;
}

inline void WindowInfoWrap::setIsValid(bool isValid) noexcept
{
    m_isValid = isValid;
}

constexpr bool WindowInfoWrap::isActive() const noexcept
{
    return m_isActive;
}

inline void WindowInfoWrap::setIsActive(bool isActive) noexcept
{
    m_isActive = isActive;
}

constexpr bool WindowInfoWrap::isMinimized() const noexcept
{
    return m_isMinimized;
}

inline void WindowInfoWrap::setIsMinimized(bool isMinimized) noexcept
{
    m_isMinimized = isMinimized;
}

constexpr bool WindowInfoWrap::isMaximized() const noexcept
{
    return m_isMaxVert || m_isMaxHorz;
}

constexpr bool WindowInfoWrap::isMaxVert() const noexcept
{
    return m_isMaxVert;
}

inline void WindowInfoWrap::setIsMaxVert(bool isMaxVert) noexcept
{
    m_isMaxVert = isMaxVert;
}

constexpr bool WindowInfoWrap::isMaxHoriz() const noexcept
{
    return m_isMaxHorz;
}

inline void WindowInfoWrap::setIsMaxHoriz(bool isMaxHoriz) noexcept
{
    m_isMaxHorz = isMaxHoriz;
}

constexpr bool WindowInfoWrap::isFullscreen() const noexcept
{
    return m_isFullscreen;
}

inline void WindowInfoWrap::setIsFullscreen(bool isFullscreen) noexcept
{
    m_isFullscreen = isFullscreen;
}

constexpr bool WindowInfoWrap::isShaded() const noexcept
{
    return m_isShaded;
}

inline void WindowInfoWrap::setIsShaded(bool isShaded) noexcept
{
    m_isShaded = isShaded;
}

constexpr bool WindowInfoWrap::isPlasmaDesktop() const noexcept
{
    return m_isPlasmaDesktop;
}

inline void WindowInfoWrap::setIsPlasmaDesktop(bool isPlasmaDesktop) noexcept
{
    m_isPlasmaDesktop = isPlasmaDesktop;
}

constexpr QRect WindowInfoWrap::geometry() const noexcept
{
    return m_geometry;
}

inline void WindowInfoWrap::setGeometry(const QRect &geometry) noexcept
{
    m_geometry = geometry;
}

constexpr WId WindowInfoWrap::wid() const noexcept
{
    return m_wid;
}

inline void WindowInfoWrap::setWid(WId wid) noexcept
{
    m_wid = wid;
}

// END: definitions
}

#endif // WINDOWINFOWRAP_H
