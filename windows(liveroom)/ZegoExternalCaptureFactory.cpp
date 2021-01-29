#include "ZegoExternalCaptureFactory.h"

ZegoExternalCaptureFactory::ZegoExternalCaptureFactory(QObject* parent)
	: QObject(parent)
{

}

ZegoExternalCaptureFactory::~ZegoExternalCaptureFactory()
{

}

AVE::VideoCaptureDevice* ZegoExternalCaptureFactory::Create(const char* device_id)
{
	m_captureDevice = new ZegoExternalCaptureDevice;
	emit sigDeviceCreated();
	return m_captureDevice;
}

void ZegoExternalCaptureFactory::Destroy(AVE::VideoCaptureDeviceBase *vc)
{
	delete m_captureDevice;
	m_captureDevice = nullptr;
	emit sigDeviceDestroyed();
}

ZegoExternalCaptureDevice* ZegoExternalCaptureFactory::Device(void)
{
	return m_captureDevice;
}

//////////////////////////////////////////////////////////////////////////////
ZegoExternalCaptureDevice::ZegoExternalCaptureDevice()
{
}

ZegoExternalCaptureDevice::~ZegoExternalCaptureDevice()
{
}

bool ZegoExternalCaptureDevice::IsCapturing(void) const
{
	return m_isCapturing;
}

AVE::VideoCaptureDevice::Client* ZegoExternalCaptureDevice::Client(void)
{
	if (!m_veClient || !m_isCapturing)
	{
		return nullptr;
	}

	return m_veClient;
}


void ZegoExternalCaptureDevice::AllocateAndStart(AVE::VideoCaptureDevice::Client* client)
{
	// ZEGO::AV::StartPublishʱ����
	m_veClient = client;

	// ���ö����ⲿ�ɼ����洦��ģʽ������Ӻڱߣ���֤�������ݿɼ������������ֱ��ʲü�
	// ֱ�������пɶ�̬�ı�
	m_veClient->SetFillMode(AVE::FILL_MODE_BLACKBAR);
}

void ZegoExternalCaptureDevice::StopAndDeAllocate()
{
	// ZEGO::AV::StopPublishʱ����
	if (m_veClient)
	{
		m_veClient->Destroy();
		m_veClient = nullptr;
	}
}

int ZegoExternalCaptureDevice::StartCapture()
{
	m_isCapturing = true;
	
	return 0;
}

int ZegoExternalCaptureDevice::StopCapture()
{
	m_isCapturing = false;
	return 0;
}

int ZegoExternalCaptureDevice::SetFrameRate(int framerate)
{
	return 0;
}

int ZegoExternalCaptureDevice::SetResolution(int width, int height)
{
	return 0;
}

int ZegoExternalCaptureDevice::SetFrontCam(int bFront)
{
	return 0;
}

int ZegoExternalCaptureDevice::SetView(void *view)
{
	return 0;
}

int ZegoExternalCaptureDevice::SetViewMode(int nMode)
{
	return 0;
}

int ZegoExternalCaptureDevice::SetViewRotation(int nRotation)
{
	return 0;
}

int ZegoExternalCaptureDevice::SetCaptureRotation(int nRotation)
{
	return 0;
}

int ZegoExternalCaptureDevice::StartPreview()
{
	return 0;
}

int ZegoExternalCaptureDevice::StopPreview()
{
	return 0;
}

int ZegoExternalCaptureDevice::EnableTorch(bool bEnable)
{
	return 0;
}

int ZegoExternalCaptureDevice::TakeSnapshot()
{
	return 0;
}

int ZegoExternalCaptureDevice::SetPowerlineFreq(unsigned int nFreq)
{
	return 0;
}