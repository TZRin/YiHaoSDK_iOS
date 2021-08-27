UNIVERSAL_OUTPUTFOLDER=../build/
WORKSPACE_NAME="${SRCROOT}/../YiHaoGamesSDK.xcworkspace"

# 创建输出目录，并删除之前的framework文件
mkdir -p "${UNIVERSAL_OUTPUTFOLDER}"
rm -rf "${UNIVERSAL_OUTPUTFOLDER}/${PROJECT_NAME}.framework"

# 分别编译模拟器和真机的Framework
xcodebuild -workspace ${WORKSPACE_NAME} -scheme "${PROJECT_NAME}" -configuration ${CONFIGURATION} -sdk iphonesimulator BUILD_DIR="${BUILD_DIR}" BUILD_ROOT="${BUILD_ROOT}" clean build OBJROOT="${OBJROOT}/DependentBuilds"
xcodebuild -workspace ${WORKSPACE_NAME} -scheme "${PROJECT_NAME}" -configuration ${CONFIGURATION} -sdk iphoneos BUILD_DIR="${BUILD_DIR}" BUILD_ROOT="${BUILD_ROOT}" build OBJROOT="${OBJROOT}/DependentBuilds"

# 拷贝framework到univer目录
cp -R "${BUILD_DIR}/${CONFIGURATION}-iphoneos/${PROJECT_NAME}.framework" "${UNIVERSAL_OUTPUTFOLDER}/"

# 删除之前的bundle
rm -rf "${UNIVERSAL_OUTPUTFOLDER}/SDKResources.bundle"

# 复制bundle文件到输出目录
cp -R "${BUILD_DIR}/${CONFIGURATION}-iphoneos/SDKResources.bundle" "${UNIVERSAL_OUTPUTFOLDER}/"
cp -R "${BUILD_DIR}/${CONFIGURATION}-iphonesimulator/SDKResources.bundle" "${UNIVERSAL_OUTPUTFOLDER}/"

# 合并framework，输出最终的framework到build目录
lipo -create -output "${UNIVERSAL_OUTPUTFOLDER}/${PROJECT_NAME}.framework/${PROJECT_NAME}" "${BUILD_DIR}/${CONFIGURATION}-iphonesimulator/${PROJECT_NAME}.framework/${PROJECT_NAME}" "${BUILD_DIR}/${CONFIGURATION}-iphoneos/${PROJECT_NAME}.framework/${PROJECT_NAME}"

