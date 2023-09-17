#include "DirectionPoint.h"
#include "TowerDefense.h"

DirectionPoint::DirectionPoint(uint dir) {

	direction = dir;

	BBox(new Rect(-10, -10, 9, 9));

	type = DIRECTIONPOINT;
}

DirectionPoint::~DirectionPoint() {

}

void DirectionPoint::Update() {

}

void DirectionPoint::OnCollision(Object* obj) {

}