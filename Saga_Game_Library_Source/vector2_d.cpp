#include "vector2_d.h"
#include "util.h"

using namespace sgl;

//--------------------------------------------------------------

Vector2D::Vector2D() : x( 0.0f ), y( 0.0f ) {}

//--------------------------------------------------------------

Vector2D::Vector2D( float fx, float fy ) : x( fx ), y( fy ) {}

//--------------------------------------------------------------

Vector2D::Vector2D( int _x, int _y ) : x( _x ), y( _y ) {}

//--------------------------------------------------------------

Vector2D::Vector2D( const Vector2D& vector ) {
	x = vector.x;
	y = vector.y;
}

//--------------------------------------------------------------

Vector2D::~Vector2D() {}

//--------------------------------------------------------------

float Vector2D::dotProduct( const Vector2D& vector ) const {
	return ( x * vector.x + y * vector.y );
}

//--------------------------------------------------------------

Vector2D Vector2D::normalize() {
		
	float m = this->magnitude();
		
	return ( m == 0 ) ? *this : Vector2D( x/m, y/m );
}

//--------------------------------------------------------------

Vector2D Vector2D::operator +( const Vector2D& vector ) const {
	return Vector2D( x + vector.x, y + vector.y );
}

//--------------------------------------------------------------

void Vector2D::operator +=( const Vector2D& vector ) {
	x += vector.x;
	y += vector.y;
}

//--------------------------------------------------------------

Vector2D Vector2D::operator -( const Vector2D& vector ) const {
	return Vector2D( x - vector.x, y - vector.y );
}

//--------------------------------------------------------------

void Vector2D::operator -=( const Vector2D& vector ) {
	x -= vector.x;
	y -= vector.y;
}

//--------------------------------------------------------------

Vector2D Vector2D::operator *( float scalar ) const {
	return Vector2D( x * scalar, y * scalar );
}

//--------------------------------------------------------------

Vector2D Vector2D::operator /( float scalar ) const {
	return Vector2D( x/scalar, y/scalar );
}

//--------------------------------------------------------------

void Vector2D::operator *=( float scalar ) {
	x *= scalar;
	y *= scalar;
}

//--------------------------------------------------------------

void Vector2D::operator /=( float n ) {
	x /= n;
	y /= n;
}

//--------------------------------------------------------------

bool Vector2D::operator !=( const Vector2D& v ) const {
	return ( x != v.x && y != v.y );
}

//--------------------------------------------------------------

bool Vector2D::operator ==( const Vector2D& v ) const {
	return ( x == v.x && y == v.y );
}

//--------------------------------------------------------------

void Vector2D::operator =( const Vector2D& v ) {
	x = v.x;
	y = v.y;
}

//--------------------------------------------------------------

float Vector2D::magnitude() const {
	return std::sqrt( x * x + y * y );
}

//--------------------------------------------------------------

float Vector2D::getX() const {
	return x;
}

//--------------------------------------------------------------

float Vector2D::getY() const {
	return y;
}

//--------------------------------------------------------------

void Vector2D::ceil() {
	x = Util::ceilFloat( x );
	y = Util::ceilFloat( y );
}

//--------------------------------------------------------------

void Vector2D::floor() {
	x = Util::floorFloat( x );
	y = Util::floorFloat( y );
}

//--------------------------------------------------------------

Vector2D Vector2D::generateVector2D( float magnitude, float angle ) {
	return Vector2D( (float) magnitude * cosf( angle ), (float) magnitude * sinf( angle ) );
}

//--------------------------------------------------------------

void Vector2D::setCoordenate(float x, float y)
{
	this->x = x;
	this->y = y;
}

//--------------------------------------------------------------

Vector2D Vector2D::operator *(const Vector2D& vec) const
{
	return Vector2D( x * vec.x, y * vec.y );
}

//--------------------------------------------------------------

Vector2D Vector2D::operator /(const Vector2D& vec) const
{
	return Vector2D( x/vec.x, y/vec.y );
}

//--------------------------------------------------------------