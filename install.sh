#!/bin/bash

# 🎨 My Paint - Installation Script
# Automatic setup for My Paint Digital Art Studio

set -e  # Exit on any error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

print_header() {
    echo -e "${PURPLE}"
    echo "  ███╗   ███╗██╗   ██╗    ██████╗  █████╗ ██╗███╗   ██╗████████╗"
    echo "  ████╗ ████║╚██╗ ██╔╝    ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝"
    echo "  ██╔████╔██║ ╚████╔╝     ██████╔╝███████║██║██╔██╗ ██║   ██║   "
    echo "  ██║╚██╔╝██║  ╚██╔╝      ██╔═══╝ ██╔══██║██║██║╚██╗██║   ██║   "
    echo "  ██║ ╚═╝ ██║   ██║       ██║     ██║  ██║██║██║ ╚████║   ██║   "
    echo "  ╚═╝     ╚═╝   ╚═╝       ╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   "
    echo -e "${NC}"
    echo -e "${CYAN}                    Digital Art Studio - Installation${NC}"
    echo -e "${YELLOW}                    Version 0.1.0-alpha (Unstable Base)${NC}"
    echo ""
}

# Detect OS
detect_os() {
    if [[ "$OSTYPE" == "darwin"* ]]; then
        OS="macos"
    elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
        OS="linux"
    else
        print_error "Unsupported operating system: $OSTYPE"
        exit 1
    fi
    print_status "Detected OS: $OS"
}

# Install dependencies
install_dependencies() {
    print_status "Installing dependencies..."
    
    if [[ "$OS" == "macos" ]]; then
        # Check if Homebrew is installed
        if ! command -v brew &> /dev/null; then
            print_error "Homebrew not found. Please install Homebrew first:"
            echo "/bin/bash -c \"\$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)\""
            exit 1
        fi
        
        print_status "Installing SFML via Homebrew..."
        brew install sfml || {
            print_warning "SFML installation failed or already installed"
        }
        
    elif [[ "$OS" == "linux" ]]; then
        # Detect Linux distribution
        if command -v apt-get &> /dev/null; then
            print_status "Installing SFML via apt-get..."
            sudo apt-get update
            sudo apt-get install -y libcsfml-dev build-essential
        elif command -v pacman &> /dev/null; then
            print_status "Installing SFML via pacman..."
            sudo pacman -S csfml base-devel
        elif command -v yum &> /dev/null; then
            print_status "Installing SFML via yum..."
            sudo yum install csfml-devel gcc make
        else
            print_error "Unsupported Linux distribution. Please install SFML manually."
            exit 1
        fi
    fi
    
    print_success "Dependencies installed successfully!"
}

# Verify installation
verify_installation() {
    print_status "Verifying installation..."
    
    # Check for required tools
    if ! command -v gcc &> /dev/null; then
        print_error "GCC compiler not found"
        exit 1
    fi
    
    if ! command -v make &> /dev/null; then
        print_error "Make not found"
        exit 1
    fi
    
    print_success "All required tools are available"
}

# Build project
build_project() {
    print_status "Building My Paint..."
    
    # Clean previous builds
    make clean &> /dev/null || true
    
    # Build main application
    if make; then
        print_success "Main application built successfully!"
    else
        print_error "Failed to build main application"
        exit 1
    fi
    
    # Build tests
    print_status "Building test suite..."
    if make -f Makefile_tests all_tests; then
        print_success "Test suite built successfully!"
    else
        print_warning "Some tests failed to build (this is not critical)"
    fi
}

# Run tests
run_tests() {
    print_status "Running tests..."
    
    if [[ -f "./test_init_all" ]]; then
        print_status "Running initialization tests..."
        if ./test_init_all; then
            print_success "Initialization tests passed!"
        else
            print_warning "Some initialization tests failed"
        fi
    fi
    
    if [[ -f "./test_components" ]]; then
        print_status "Running component tests..."
        if ./test_components; then
            print_success "Component tests passed!"
        else
            print_warning "Some component tests failed"
        fi
    fi
}

# Show usage information
show_usage() {
    echo -e "${GREEN}"
    echo "🎉 Installation completed successfully!"
    echo -e "${NC}"
    echo "📋 Usage:"
    echo "  ./my_paint                    # Launch My Paint"
    echo "  make clean && make            # Rebuild application"
    echo "  make -f Makefile_tests all_tests  # Build all tests"
    echo "  ./test_init_all               # Run initialization tests"
    echo ""
    echo "📚 Documentation:"
    echo "  README.md                     # Main documentation"
    echo "  README_TESTS.md               # Testing guide"
    echo "  CONTRIBUTING.md               # Contribution guide"
    echo "  CHANGELOG.md                  # Version history"
    echo ""
    echo -e "${YELLOW}⚠️  Remember: This is an UNSTABLE version - development base only!${NC}"
    echo ""
}

# Main installation process
main() {
    print_header
    
    print_status "Starting My Paint installation..."
    echo ""
    
    detect_os
    install_dependencies
    verify_installation
    build_project
    run_tests
    
    echo ""
    show_usage
}

# Handle script arguments
case "${1:-}" in
    --help|-h)
        echo "My Paint Installation Script"
        echo ""
        echo "Usage: $0 [options]"
        echo ""
        echo "Options:"
        echo "  --help, -h     Show this help message"
        echo "  --deps-only    Install dependencies only"
        echo "  --build-only   Build project only (skip dependency installation)"
        echo "  --no-tests     Skip running tests"
        echo ""
        exit 0
        ;;
    --deps-only)
        print_header
        detect_os
        install_dependencies
        print_success "Dependencies installation completed!"
        ;;
    --build-only)
        print_header
        verify_installation
        build_project
        print_success "Build completed!"
        ;;
    --no-tests)
        print_header
        detect_os
        install_dependencies
        verify_installation
        build_project
        show_usage
        ;;
    "")
        main
        ;;
    *)
        print_error "Unknown option: $1"
        echo "Use --help for usage information"
        exit 1
        ;;
esac