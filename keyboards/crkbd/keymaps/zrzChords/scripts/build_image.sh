#!/bin/bash
echo "🔧 Building Docker image: qmk-corne"
docker build -t qmk-corne -f docker/Dockerfile
